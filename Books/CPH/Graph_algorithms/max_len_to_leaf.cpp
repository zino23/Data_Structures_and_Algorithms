#include <vector>
using namespace std;

const int N = 1e5 + 10;
vector<int> head[N];
bool visited[N];
int to_leaf[N];

void dfs(int x) {
  // The length to itself is 0
  to_leaf[x] = 0;
  int tmp = 0;
  for (auto i : head[x]) {
    // A tree is a acyclic graph, so this only prevents i from visiting x
    if (!visited[i]) {
      visited[i] = true;
      dfs(i);
      // Find the child with the maximum length to leaf
      tmp = max(tmp, to_leaf[i]);
    }
  }
  to_leaf[x] += tmp + 1;
}
