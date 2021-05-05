#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int res;
  const static int N = 60;
  bool a[N][N] = { false };

  int bfs( int threshold, int rows, int cols ) {
    int d_x[4] = { 0, 1, 0, -1 }, d_y[4] = { 1, 0, -1, 0 };
    queue<pair<int, int>> q;
    if ( rows == 0 || cols == 0 ) return 0;
    q.push( { 0, 0 } );
    a[0][0] = true;
    int res = 1;
    while ( !q.empty() ) {
      auto t = q.front();
      int x = t.first, y = t.second;
      q.pop();
      for ( int i = 0; i < 4; i++ ) {
        int new_x = x + d_x[i], new_y = y + d_y[i];
        if ( new_x >= 0 && new_x < cols && new_y >= 0 && new_y < rows &&
             !a[new_x][new_y] &&
             new_x / 10 + new_x % 10 + new_y / 10 + new_y % 10 <= threshold ) {
          q.push( { new_x, new_y } );
          a[new_x][new_y] = true;
          res++;
        }
      }
    }
    return res;
  }

  void dfs( int x, int y, int threshold, int rows, int cols ) {
    int d_x[4] = { 0, 1, 0, -1 }, d_y[4] = { 1, 0, -1, 0 };
    for ( int i = 0; i < 4; i++ ) {
      int new_x = x + d_x[i], new_y = y + d_y[i];
      if ( new_x >= 0 && new_x < cols && new_y >= 0 && new_y < rows &&
           !a[new_x][new_y] &&
           new_x / 10 + new_x % 10 + new_y / 10 + new_y % 10 <= threshold ) {
        a[new_x][new_y] = true;
        res++;
        dfs( new_x, new_y, threshold, rows, cols );
      }
    }
  }

  int movingCount( int threshold, int rows, int cols ) {
    res = 0;
    dfs( 0, -1, threshold, rows, cols );
    res = bfs( threshold, rows, cols );
    return res;
  }
};

int main() { return 0; }

