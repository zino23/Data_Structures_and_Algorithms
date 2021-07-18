#include <iostream>

using namespace std;

typedef unsigned long long PLL;
const int p = 31,
          mod = 1e9 + 9;  // mod 2^64 is implicit if use type unsigned long long
const int N = 1e5 + 10;
char s[N];
PLL pre_sum[N], p_pow[N];

PLL get_num( int l, int r ) {
  return pre_sum[r] - pre_sum[l - 1] * p_pow[r - l + 1];
}

int main() {
  int n, m;
  cin >> n >> m;
  p_pow[0] = 1;
  for ( int i = 1; i <= n; i++ ) {
    cin >> s[i];
    pre_sum[i] = ( pre_sum[i - 1] * p + s[i] - 'a' + 1 ) % mod;
    p_pow[i] = p_pow[i - 1] * p;
  }

  while ( m-- ) {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if ( get_num( l1, r1 ) == get_num( l2, r2 ) ) {
      cout << "Yes";
    } else {
      cout << "No";
    }
    cout << endl;
  }
  return 0;
}
