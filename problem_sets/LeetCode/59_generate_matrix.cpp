#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    int x = 0, y = 0;
    for (int i = 1, d = 0; i <= n * n; i++) {
      res[x][y] = i;
      visited[x][y] = true;
      int new_x = x + dx[d];
      int new_y = y + dy[d];
      if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n ||
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
