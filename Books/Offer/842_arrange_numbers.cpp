#include <iostream>

using namespace std;

const int N = 10;
int path[N];
bool visited[N];
int n;

void dfs(int u) {
  // path[0:u - 1] is completed
  if (u == n) {
    for (int i = 0; i < n; i++) {
      cout << path[i] << ' ';
    }
    cout << endl;
  }

  // Cos all the numbers are different, we need only consider the numbers that
  // has been used in current path
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      visited[i] = true;
      path[u] = i;
      dfs(u + 1);
      // When return from dfs(u + 1), a complete path has been found, need to
      // reset path[u] and mark i as unvisited Note: the reset of path[u] can be
      // left out cos in the next iteration it will be assigned the value of
      // another path
      path[u] = 0;
      visited[i] = false;
    }
  }
}

int main() {
  cin >> n;
  dfs(0);
  return 0;
}
