#include <vector>

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    vector<int> res;
    int x = 0, y = 0;
    for (int i = 0, d = 0; i < m * n; i++) {
      res.push_back(mat[x][y]);
      visited[x][y] = true;
      int new_x = x + dx[d];
      int new_y = y + dy[d];
      if (new_x >= m || new_x < 0 || new_y >= n | new_y < 0 ||
          visited[new_x][new_y]) {
        d = (d + 1) % 4;
        new_x = x + dx[d];
        new_y = y + dy[d];
      }
      x = new_x;
      y = new_y;
    }
    return res;
  }
};
