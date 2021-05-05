#include <iostream>
#include <vector>
using namespace std;

const int N = 210;
bool is_connected[N][N];
vector<bool> visited;
int n;
int ans, tmp;

void dfs(int x) {
  visited[x] = true;

  for (int i = 0; i < n; i++) {
    if (is_connected[x][i] && !visited[i]) {
      // Find a new cow
      tmp++;
      dfs(i);
    }
  }
}

int main() {
  cin >> n;
  vector<int> x(n), y(n), p(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> p[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int dist_x2y =
          (x[i] - x[j]) * (x[i] * x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
      int limit = p[i] * p[i];
      if (dist_x2y <= limit) {
        is_connected[i][j] = true;
      }
    }
  }

  for (int i = 0; i <= n; i++) {
    visited.assign(n, false);
    // Start with cow i, the result includes i
    tmp = 1;
    dfs(i);
    ans = max(ans, tmp);
  }

  cout << ans << endl;
  return 0;
}
