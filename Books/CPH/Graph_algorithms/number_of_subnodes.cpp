#include <vector>
using namespace std;

const int N = 1e5 + 10;
vector<int> head[N];
bool visited[N];
int cnt[N];

void dfs(int x) {
  cnt[x] = 1;
  for (auto i : head[x]) {
    if (!visited[i]) {
      visited[i] = true;
      dfs(i);
      cnt[x] += cnt[i];
    }
  }
}
