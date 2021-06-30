#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

// An array of vectors
vector<int> head[N];
int cc[N];
int res = -1;
// State for each node indicating if this node has been visited
bool st[N];

void dfs( int x ) {
  // Mark x as visited
  st[x] = true;
  for ( auto i : head[x] ) {
    if ( !st[i] ) {
      dfs( i );
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  while ( m-- ) {
    int a, b;
    cin >> a >> b;
    head[a].push_back( b ), head[b].push_back( a );
  }

  for ( int i = 1; i <= n; i++ ) {
    if ( !st[i] ) {
      res++;
      cc[res] = i;
      dfs( i );
    }
  }

  cout << res << endl;
  for ( int i = 1; i <= res; i++ ) {
    cout << cc[0] << ' ' << cc[i] << endl;
  }
  return 0;
}

/******************************
 * Linked list implementation *
 ******************************/

// const int N = 2e5 + 10;
// int n, m;
// int a[N];
// int head[N];
// int ne[N], e[N], idx = 0;
// int connected_components[N];

// // Insert an edge that connect x to y
// void insert( int x, int y ) {
//   // Store the value
//   e[idx] = y;
//   // Store the next pointer
//   ne[idx] = head[x];
//   head[x] = idx++;
// }

// // State for each node indicating if it has been visited
// bool st[N];
// int res = -1;
// void dfs( int x ) {
//   for ( int i = head[x]; i != -1; i = ne[i] ) {
//     int next = e[i];
//     if ( !st[next] ) {
//       st[next] = true;
//       dfs( next );
//     }
//   }
// }

// int main() {
//   cin >> n >> m;
//   memset( head, -1, sizeof head );

//   while ( m-- ) {
//     int a, b;
//     cin >> a >> b;
//     insert( a, b ), insert( b, a );
//   }

//   for ( int i = 1; i <= n; i++ ) {
//     if ( !st[i] ) {
//       res++;
//       connected_components[res] = i;
//       st[i] = true;
//       dfs( i );
//     }
//   }
//   cout << res << endl;
//   for ( int i = 0; i < res; i++ ) {
//     cout << connected_components[0] << ' ' << connected_components[1 + i]
//          << endl;
//   }
//   return 0;
// }
