#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
vector<int> h[N]; // adjacency list for each node
bool st[N];       // if is visited

void dfs(int x) {
  if (st[x])
    return;
  st[x] = true;

  for (auto i : h[x]) {
    dfs(i);
  }
}

