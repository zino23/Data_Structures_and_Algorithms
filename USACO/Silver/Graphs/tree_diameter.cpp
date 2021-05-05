#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int N = 2e5 + 10;
vector<int> h[N];
int to_leaf[N];
int child[N];  // Child node on the path to the furtherest leaf

void dfs(int x, int p) {
  to_leaf[x] = 0;
  int max_len = 0;
  for (auto i : h[x]) {
    if (i != p) {
      dfs(i, x);
      if (to_leaf[i] > max_len) {
        max_len = to_leaf[i];
        child[x] = i;
      }
    }
  }
  to_leaf[x] = max_len + 1;
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    h[a].push_back(b), h[b].push_back(a);
  }

  // Initialize child to itself
  for (int i = 1; i <= n; i++) {
    child[i] = i;
  }
  // Begin on any node
  dfs(1, 1);
  // Find the furtherest leaf of node 1
  int cur = 1;
  bool visited[N];
  memset(visited, false, sizeof visited);
  while (!visited[cur]) {
    visited[cur] = true;
    cur = child[cur];
  }

  // Reinitialize
  for (int i = 1; i <= n; i++) {
    child[i] = i;
  }

  // Now start with the furtherest leaf to 3
  dfs(cur, cur);
  int diameter = 0;
  memset(visited, false, sizeof visited);
  while (!visited[cur]) {
    visited[cur] = true;
    cur = child[cur];
    diameter++;
  }
  cout << (diameter - 1) << endl;
  return 0;
}
