#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> PII;
const int N = 110;
int n, m;
int g[N][N], d[N][N];
queue<PII> q;

int bfs(int x, int y) {
  d[0][0] = 1;
  q.push({x, y});
  int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
  while (q.size() ||
         (x == n - 1 && y == m - 1)) // terminate when there are no more roads
  {
    auto t = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      x = t.first + dx[i], y = t.second + dy[i];
      if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == 0) {
        d[x][y] = d[t.first][t.second] + 1;
        g[x][y] = d[x][y] - 1;
        q.push({x, y});
      }
    }
  }

  return d[n - 1][m - 1] - 1;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> g[i][j];

  cout << bfs(0, 0) << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cout << g[i][j];
    cout << endl;
  }

  return 0;
}
