#include <algorithm>
#include <cstring>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
vector<int> head[N];
bool visited[N];
int to_leaf[N], max_len[N];
int n;  // The number of nodes

void dfs(int x) {
  to_leaf[x] = 0;
  int tmp = 0;
  for (auto i : head[x]) {
    if (!visited[i]) {
      visited[i] = true;
      dfs(i);
      // Find the child with the maximum length to leaf
      tmp = max(tmp, to_leaf[i]);
    }
  }
  to_leaf[x] += tmp + 1;
}

void calc_max_length(int x) {
  // For root node x, select two child nodes a and b so that the sum of
  // to_leaf[a] and to_leaf[b] is the biggest. Add 2 to this sum we get the max
  // length with x being the root. One of the paths corresponds to the diameter
  if (head[x].size() == 1) {
    max_len[x] = to_leaf[x];
    return;
  }
  vector<int> child_lengths;
  for (auto i : head[x]) {
    child_lengths.push_back(to_leaf[i]);
  }
  sort(child_lengths.begin(), child_lengths.end(), greater<int>());
  max_len[x] = child_lengths[0] + child_lengths[1] + 2;
}

int child_node[N];
// Return the child node that is in the path that has the largest length
void dfs(int x, int parent) {
  to_leaf[x] = 0;
  int tmp = 0;
  for (auto i : head[x]) {
    if (i != parent) {
      dfs(i, x);
      if (to_leaf[i] > tmp) {
        tmp = to_leaf[i];
        child_node[x] = i;
      }
    }
  }
  to_leaf[x] = tmp + 1;
}

int main() {
  int n, m;
  int diameter;
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    head[a].push_back(b), head[b].push_back(a);
  }

  // 1. A naive implementation
  // for (int i = 1; i <= n; i++) {
  //   dfs(i);
  //   calc_max_length(i);
  // }
  // sort(max_len + 1, max_len + n + 1);
  // diameter = max_len[n];

  // 2. A better one with two dfs
  for (int i = 1; i <= n; i++) {
    child_node[i] = i;
  }
  dfs(3, 3);
  auto cur = 3;
  vector<int> path;
  while (!visited[cur]) {
    visited[cur] = true;
    path.push_back(cur);
    cur = child_node[cur];
  }
  cout << "From " << cur << " to its furtherest leaf: " << endl;
  for (auto i : path) {
    cout << i << endl;
  }

  // Reinitialize
  for (int i = 1; i <= n; i++) {
    child_node[i] = i;
  }
  memset(visited, false, n);
  dfs(cur, cur);
  path.clear();
  while (!visited[cur]) {
    visited[cur] = true;
    path.push_back(cur);
    cur = child_node[cur];
  }
  cout << endl << "From " << cur << " to its furtherest leaf: " << endl;
  for (auto i : path) {
    cout << i << endl;
  }
  return 0;
}

