class Solution {
 public:
  int getMaxValue(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int f[m + 1][n + 1];
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        f[i][j] = max(f[i][j - 1], f[i - 1][j]) + grid[i - 1][j - 1];
      }
    }
    return f[m][n];
  }
};
