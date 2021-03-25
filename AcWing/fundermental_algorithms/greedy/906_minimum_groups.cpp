#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> PII;
const int N = 1e5 + 10;
PII interval[N];

int main() {
  int n, a, b;
  cin >> n;
  for ( int i = 0; i < n; i++ ) {
    cin >> a >> b;
    interval[i] = { a, b };
  }

  sort( interval, interval + n,
        []( PII a, PII b ) { return a.first < b.first; } );

  // O(n^2)
  // int ans = 1;
  // int max_r[N];
  // memset(max_r, 0, sizeof max_r);
  // max_r[1] = interval[0].second;
  // for ( int i = 1; i < n; i++ ) {
  //   bool new_group = true;
  //   for ( int j = 1; j <= ans; j++ ) {
  //     if ( max_r[j] < interval[i].first ) {
  //       max_r[j] = interval[i].second;
  //       new_group = false;
  //       break;
  //     }
  //   }
  //   if ( new_group ) {
  //     max_r[++ans] = interval[i].second;
  //   }
  // }

  // O(nlogn)
  priority_queue<int, vector<int>, greater<int>> heap;
  for ( int i = 0; i < n; i++ ) {
    auto x = interval[i];
    if ( heap.empty() || x.first <= heap.top() ) {
      heap.push( x.second );
    } else {
      heap.pop();
      heap.push( x.second );
    }
  }
  int ans = heap.size();
  cout << ans << endl;
  return 0;
}
