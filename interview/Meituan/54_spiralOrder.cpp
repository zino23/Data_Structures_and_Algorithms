#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return {};
    int row = matrix.size();
    int col = matrix[0].size();

    vector<vector<bool>> visited(row, vector<bool>(col, false));

    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    int cnt = 0;
    vector<int> res;
    int x = 0, y = 0;
    int d = 0;
    while (cnt < row * col) {
      visited[x][y] = true;
      res.push_back(matrix[x][y]);
      int new_x = x + dx[d];
      int new_y = y + dy[d];
      if (new_x < 0 || new_x >= row || new_y < 0 || new_y >= col ||
          visited[new_x][new_y]) {
        d = (d + 1) % 4;
        new_x = x + dx[d];
        new_y = y + dy[d];
      }
      x = new_x;
      y = new_y;
      cnt++;
    }
    return res;
  }
};
