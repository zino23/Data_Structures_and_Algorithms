#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
vector<PII> interval;

int main() {
  int n, a, b;
  cin >> n;
  for ( int i = 0; i < n; i++ ) {
    cin >> a >> b;
    interval.push_back( { a, b } );
  }

  // sort according to right endpoint
  sort( interval.begin(), interval.end(),
        []( PII a, PII b ) { return a.second < b.second; } );

  int ans = 0;

  // 1. traverse over the intervals
  // int ed = -2e9 - 10;
  // for ( auto x : interval ) {
  //   if ( x.first > ed ) {
  //     ans++;
  //     ed = x.second;
  //   }
  // }

  // 2. move pointer i to next interval
  int i = 0;
  while ( i < interval.size() ) {
    ans++;
    int right = interval[i].second;
    while ( interval[++i].first <= right && i < interval.size() ) {
    };
  }

  cout << ans << endl;
  return 0;
}
