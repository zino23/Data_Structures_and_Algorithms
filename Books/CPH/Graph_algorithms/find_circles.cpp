#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
vector<int> h[N];
bool st[N];
bool has_cycle;

// Check if a cycle exists
void dfs( int x ) {
  if ( st[x] ) {
    has_cycle = true;
    return;
  }
  st[x] = true;

  for ( auto i : h[x] ) {
    dfs( i );
  }
}

