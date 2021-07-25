#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int res = 0;
    using pos = pair<int, int>;
    queue<pos> q;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (!visited[i][j]) {
          q.push({i, j});
          visited[i][j] = true;

          /* Find connected chars which are the same as grid[i][j] */
          char type = grid[i][j];
          if (type == '1') {
            res++;
          }
          while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
              int new_x = p.first + dx[d];
              int new_y = p.second + dy[d];
              if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n &&
                  !visited[new_x][new_y] && grid[new_x][new_y] == type) {
                q.push({new_x, new_y});
                visited[new_x][new_y] = true;
              }
            }
          }
        }
      }
    }
    return res;
  }
};
