#include <cstring>
#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
  int x = 0, y = 0;
  int res[n][m];
  bool st[n][m];
  memset(st, false, sizeof(st));
  for (int i = 1, d = 0; i <= n * m; i++) {
    res[x][y] = i;
    st[x][y] = true;
    int new_x = x + dx[d], new_y = y + dy[d];
    if (new_x < 0 || new_x > n - 1 || new_y < 0 || new_y > m - 1 ||
        st[new_x][new_y]) {
      d = (d + 1) % 4;
      new_x = x + dx[d], new_y = y + dy[d];
    }
    x = new_x, y = new_y;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) { cout << res[i][j] << " "; }
    cout << endl;
  }
  return 0;
}
