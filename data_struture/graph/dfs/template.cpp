#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
// the graph is stored as adjacency lists in an array
vector<int> adj[N];
// keep track of visited nodes
bool visited[N];

void dfs(int x) {
  if (visited[x]) return;

  visited[x] = true;
  for (auto i : adj[x]) { dfs(i); }
}
