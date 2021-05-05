#include <iostream>
#include <ostream>
#include <vector>

const int N = 1e5 + 10;
std::vector<int> h[N];
bool st[N];
bool color[N];
bool ans = true;

void dfs( int x ) {
  st[x] = true;
  for ( auto i : h[x] ) {
    // Paint x's neighbor with different color
    // If the node has not been visited, paint will always succedd
    if ( !st[x] ) {
      color[i] = !color[x];
      dfs( i );
    } else {
      if ( color[i] == color[x] ) {
        ans = false;
        break;
      }
    }
  }
}

int main() {
  // Construct the graph, assume total n nodes are numbered as 1:n

  // Start at 1
  dfs( 1 );
  std::cout << ans << std::endl;
  return 0;
}
