class Solution {
public:
  vector<int> printMatrix(vector<vector<int>> matrix) {
    if (matrix.size() == 0 || matrix.at(0).size() == 0)
      return {};

    int row = matrix.size();
    int col = matrix.at(0).size();
    vector<int> res;
    // Initialize and mark all as unvisited
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

    int x = 0, y = 0;
    int d = 0;
    int cnt = 0;
    // The while loop move by one position
    while (cnt != row * col) {
      // Current position (x, y) is feasible
      res.push_back(matrix[x][y]);
      visited[x][y] = true;
      int new_x = x + dx[d];
      int new_y = y + dy[d];

      // Need to change direction
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

