#include <cstring>
#include <iostream>

using namespace std;

int n, m;
const int N = 110;
int v[N][N], w[N][N], s[N];

int naive() {
  int f[N][N];
  memset( f, 0, sizeof f );

  for ( int i = 1; i <= n; i++ ) {
    for ( int j = 1; j <= m; j++ ) {
      // do not select any item in group k
      f[i][j] = f[i - 1][j];
      for ( int k = 0; k <= s[i]; k++ ) {
        if ( j >= v[i][k] )
          f[i][j] = max( f[i][j], f[i - 1][j - v[i][k]] + w[i][k] );
      }
    }
  }
  return f[n][m];
}

int opt() {
  int f[N];
  memset( f, 0, sizeof f );

  for ( int i = 1; i <= n; i++ ) {
    for ( int j = m; j >= 0; j-- ) {
      for ( int k = 1; k <= s[i]; k++ ) {
        if ( j >= v[i][k] ) f[j] = max( f[j], f[j - v[i][k]] + w[i][k] );
      }
    }
  }
  return f[m];
}

int main() {
  cin >> n >> m;
  for ( int i = 1; i <= n; i++ ) {
    cin >> s[i];
    for ( int j = 1; j <= s[i]; j++ ) {
      cin >> v[i][j] >> w[i][j];
    }
  }

  // cout << naive() << endl;
  cout << opt() << endl;
  return 0;
}
