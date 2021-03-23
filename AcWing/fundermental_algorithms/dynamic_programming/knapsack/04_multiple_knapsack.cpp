#include <cstring>
#include <iostream>

using namespace std;

int n, m;
const int N = 20010;
int v[N], w[N], s[N];
int cnt;  // new item number after packing

int naive() {
  int f[N][N];

  // select items from 1:i
  for ( int i = 1; i <= n; i++ ) {
    // with volumn no larger than j
    for ( int j = 1; j <= m; j++ ) {
      // item i number no larger than k
      for ( int k = 0; k <= s[i] && k * v[i] <= j; k++ ) {
        f[i][j] = max( f[i][j], f[i - 1][j - k * v[i]] + k * w[i] );
      }
    }
  }

  return f[n][m];
}

int opt() {
  int f[N];
  memset( f, 0, sizeof f );
  for ( int i = 1; i <= cnt; i++ ) {
    for ( int j = m; j >= v[i]; j++ ) {
      f[j] = max( f[j], f[j - v[i]] + w[i] );
    }
  }
  return f[m];
}

int main() {
  cin >> n >> m;

  // navie
  // for ( int i = 1; i <= n; i++ ) {
  //   cin >> v[i] >> w[i] >> s[i];
  // }

  // binary optimization
  for ( int i = 1; i <= n; i++ ) {
    int a, b, c;
    cin >> a >> b >> c;
    int k = 1;
    while ( k <= c ) {
      cnt++;
      v[cnt] = a * k;
      w[cnt] = b * k;
      // remain items to pack
      c -= k;
      k *= 2;
    }
    if ( c > 0 ) {
      cnt++;
      v[cnt] = a * c;
      w[cnt] = b * c;
    }
  }
  // cout << naive() << endl;
  cout << opt() << endl;
  return 0;
}
