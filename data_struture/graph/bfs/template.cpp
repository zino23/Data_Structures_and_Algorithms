#include <queue>
#include <vector>
using namespace std;

const int N = 1e5;
vector<int> adj[N];
int dist[N];
bool visited[N];

void dfs(int x) {
  queue<int> q;
  q.push(x);
  visited[x] = true;
  dist[x] = 0;

  while (!q.empty()) {
    auto node = q.front();
    q.pop();

    for (auto i : adj[node]) {
      if (visited[i]) continue;
      visited[i] = true;
      q.push(i);
      dist[i] = dist[node] + 1;
    }
  }
}
