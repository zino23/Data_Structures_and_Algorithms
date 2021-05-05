#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
vector<int> h[N];
bool st[N], color[N];
long long n1, n2;

void dfs( int x ) {
  st[x] = true;
  if ( color[x] ) {
    n1++;
  } else {
    n2++;
  }
  for ( auto i : h[x] ) {
    if ( !st[i] ) {
      color[i] = !color[x];
      dfs( i );
    }
  }
}

int main() {
  int n;
  cin >> n;
  int m = n - 1;
  while ( m-- ) {
    int u, v;
    cin >> u >> v;
    h[u].push_back( v );
    h[v].push_back( u );
  }

  dfs( 1 );
  cout << n1 * n2 - n + 1 << endl;
  return 0;
}
