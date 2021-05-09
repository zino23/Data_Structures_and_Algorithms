#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  using PII = pair<int, int>;
  bool dfs(vector<vector<char>> &matrix, PII pos, int idx, string &str,
           vector<vector<bool>> &visited) {
    int x = pos.first, y = pos.second;
    if (matrix[x][y] != str[idx])
      return false;
    // Find a path
    if (idx == str.size() - 1)
      return true;

    int row = matrix.size();
    int col = matrix[0].size();
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
      int new_x = x + dx[i];
      int new_y = y + dy[i];
      if (new_x >= 0 && new_x < row && new_y >= 0 && new_y < col &&
          !visited[new_x][new_y]) {
        if (dfs(matrix, {new_x, new_y}, idx + 1, str, visited)) {
          return true;
        }
      }
    }
    visited[x][y] = false;
    return false;
  }

  bool hasPath(vector<vector<char>> &matrix, string &str) {
    if (matrix.size() == 0 || matrix[0].size() == 0)
      return false;
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        // Start match from {i, j}
        if (dfs(matrix, {i, j}, 0, str, visited)) {
          return true;
        }
      }
    }
    return false;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> matrix(n, vector<char>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> matrix[i][j];
    }
  }
  string str(2, 'a');
  auto s = new Solution();
  if (s->hasPath(matrix, str)) {
    cout << "true";
  } else {
    cout << "false";
  }
  cout << endl;
  return 0;
}
