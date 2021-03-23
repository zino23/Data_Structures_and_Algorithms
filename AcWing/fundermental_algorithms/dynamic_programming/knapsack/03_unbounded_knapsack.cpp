#include <cstring>
#include <iostream>

using namespace std;

int n, m;
const int N = 1e3 + 10;
int v[N], w[N];

int naive()
{
  int f[N][N];
  memset( f, 0, sizeof f );
  for ( int i = 1; i <= n; i++ ){
    for ( int j = 1; j <= m; j++ ){
      for ( int k = 0; k * v[i] <= j; k++ ){
        f[i][j] = max( f[i][j], f[i - 1][j - k * v[i]] + k * w[i] );
      }
    }
  }
  return f[n][m];
}

int opt() {
  int f[N];
  memset( f, 0, sizeof f );
  for ( int i = 1; i <= n; i++ ) {
    for ( int j = v[i]; j <= m; j++ ) {
      // Compared to 0-1 backpack, f[i][] still only depends on f[i - 1][]
      // so the first dimension can be left out

      // in the innerest loop, we are trying to calculate the max of
      // f[j], f[j - v[i]] + w[i], ..., f[j - x * v[i]] + x * w[i]
      // when j = current_j - v[i]
      // we have calcualted the max of
      // f[j - v[i]], f[j - 2 * v[i]] + w[i], ..., f[j - x * v[i]] + (x - 1) *
      // w[i] which is smaller than what we want to calculate by w[i] so we can
      // safely replace the loop with
      f[j] = max( f[j], f[j - v[i]] + w[i] );
    }
  }
  return f[m];
}

int main(){
  cin >> n >> m;
  for ( int i = 1; i <= n; i++ ){
    cin >> v[i] >> w[i];
  }

  cout << naive() << endl;
  cout << opt() << endl;
  return 0;
}
