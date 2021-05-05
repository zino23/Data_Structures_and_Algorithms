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
  bool dfs( vector<vector<char>>& matrix, string& str, int pos, int x, int y ) {
    if ( pos == str.size() ) return true;
    if ( matrix[x][y] != str[pos] ) return false;
    int dirt_x[4] = { 0, 1, 0, -1 };
    int dirt_y[4] = { 1, 0, -1, 0 };
    int row = matrix.size(), col = matrix[0].size();

    // matrix[x][y] match str[u], save matrix[x][y] for backtracking
    char t = matrix[x][y];
    // set matrix[x][y] to '*' so it will not be used twice
    matrix[x][y] = '*';
    for ( int i = 0; i < 4; i++ ) {
      int new_x = x + dirt_x[i], new_y = y + dirt_y[i];
      if ( new_x >= 0 && new_x < row && new_y >= 0 && new_y < col ) {
        if ( dfs( matrix, str, pos + 1, new_x, new_y ) ) {
          return true;
        }
      }
    }
    matrix[x][y] = t;
    return false;
  }

  bool hasPath( vector<vector<char>>& matrix, string& str ) {
    int row = matrix.size(), col = matrix[0].size();
    for ( int i = 0; i < row; i++ ) {
      for ( int j = 0; j < col; j++ ) {
        if ( dfs( matrix, str, 0, i, j ) ) {
          return true;
        }
      }
    }
    return false;
  }
};

int main() { return 0; }

