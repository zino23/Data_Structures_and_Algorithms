#include <iostream>
#include <vector>

using namespace std;

const int N = 1e3 + 10;
int n, m;
int v[N], w[N];

int naive() {
  int f[N][N];
  // boundary: f[0][0:m]
  // if f[][] is global, this initialization can be left out
  for ( int i = 0; i <= m; i++ ) f[0][i] = 0;

  // select i items from 1:i
  for ( int i = 1; i <= n; i++ ) {
    // with volumn no more than m
    for ( int j = 1; j <= m; j++ ) {
      // does not select item i
      f[i][j] = f[i - 1][j];
      if ( j >= v[i] ) f[i][j] = max( f[i][j], f[i - 1][j - v[i]] + w[i] );
    }
  }
  return f[n][m];
}

int opt() {
  int f[N];
  memset( f, 0, sizeof f );
  // since f[i][] only depends on f[i - 1[], the first dimension can be deleted
  for ( int i = 1; i <= n; i++ ) {
    // iterate j from max value to
    // make sure f[j - v[i]] is calculated in previous i-loop
    // i.e. f[i - 1][j - v[i]] instead of the current i-loop f[i][j - v[i]]
    for ( int j = m; j >= v[i]; j-- ) {
      f[j] = max( f[j], f[j - v[i]] + w[i] );
    }
  }

  return f[m];
}

pair<int, int> solution[N];
int opt_with_solution() {
  int f[N];
  memset( f, 0, sizeof f );

  for ( int i = 1; i <= n; i++ ) {
    for ( int j = m; j >= v[i]; j-- ) {
      int tmp = f[j - v[i]] + w[i];
      if ( tmp > f[j] ) {
        f[j] = tmp;
        solution[j] = { j - v[i], i };
      }
    }
  }
  return f[m];
}

int main() {
  cin >> n >> m;
  for ( int i = 1; i <= n; i++ ) {
    cin >> v[i] >> w[i];
  }

  cout << naive() << endl;
  cout << opt() << endl;
  cout << opt_with_solution() << endl;

  vector<int> items;
  for ( int i = m; i != 0; i = solution[i].first ) {
    items.push_back( solution[i].second );
  }

  for ( auto i : items ) {
    cout << i << ' ';
  }
  cout << endl;
  return 0;
}
