#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int f[m + 1][n + 1];
    memset(f, 0, sizeof(f));

    /* The first row */
    for (int i = 1; i <= n; i++) {
      f[1][i] = f[1][i - 1] + grid[0][i - 1];
    }

    /* The first column */
    for (int i = 1; i <= m; i++) {
      f[i][1] = f[i - 1][1] + grid[i - 1][0];
    }

    for (int i = 2; i <= m; i++) {
      for (int j = 2; j <= n; j++) {
        f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i - 1][j - 1];
      }
    }
    return f[m][n];
  }
};
