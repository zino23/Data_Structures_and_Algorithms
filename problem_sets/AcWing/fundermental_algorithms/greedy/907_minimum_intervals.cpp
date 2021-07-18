#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
typedef pair<int, int> PII;
PII interval[N];

int main() {
  int n, s, t, a, b;
  cin >> s >> t >> n;
  for ( int i = 0; i < n; i++ ) {
    cin >> a >> b;
    interval[i] = { a, b };
  }

  sort( interval, interval + n,
        []( PII a, PII b ) { return a.first < b.first; } );

  int ans = 0;
  bool find = false;
  for ( int i = 0; i < n; i++ ) {
    int j = i, s_tmp = -2e9 - 10;
    while ( j < n && interval[j].first <= s ) {
      s_tmp = max( s_tmp, interval[i].second );
      j++;
    }

    if ( s_tmp < s ) {
      ans = -1;
      break;
    }

    ans++;
    if ( s_tmp >= t ) {
      find = true;
      break;
    }

    s = s_tmp;
    i = j - 1;  // because i will increment by one in the outside loop
  }

  if ( find )
    cout << ans;
  else
    cout << -1;
  cout << endl;
  return 0;
}
