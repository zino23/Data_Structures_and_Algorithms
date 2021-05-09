class Solution {
 public:
  vector<int> printMatrix(vector<vector<int>> matrix) {
    if (matrix.size() == 0 || matrix.at(0).size() == 0) return {};

    int row = matrix.size();
    int col = matrix.at(0).size();
    vector<int> res;
    // Mark all as unvisited
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    int x = 0, y = 0;
    int d = 0;
    visited[x][y] = true;
    // for (int i = 0; i < row; i++) {
    //   for (int j = 0; j < col; j++) {
    //     cout << matrix[i][j] << ' ';
    //   }
    //   cout << endl;
    // }

    res.push_back(matrix[x][y]);
    int cnt = 1;
    while (cnt != row * col) {
      int new_x = x + dx[d];
      int new_y = y + dy[d];
      while (new_x >= 0 && new_x < row && new_y >= 0 && new_y < col &&
             !visited[new_x][new_y]) {
        x = new_x;
        y = new_y;
        visited[x][y] = true;
        res.push_back(matrix[x][y]);
        new_x = x + dx[d];
        new_y = y + dy[d];
        cnt++;
      }
      d = (d + 1) % 4;
    }
    return res;
  }
};

