#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5 + 10;
vector<int> h[N];
bool visited[N];
int subordinates[N];

void dfs(int x) {
  // The subordinates of x includes x itself here
  subordinates[x] = 1;

  for (auto i : h[x]) {
    if (!visited[i]) {
      visited[x] = true;
      dfs(i);
      subordinates[x] += subordinates[i];
    }
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int parent;
    cin >> parent;
    h[parent].push_back(i + 1);
  }

  dfs(1);
  for (int i = 1; i <= n; i++) {
    cout << (subordinates[i] - 1) << ' ';
  }
  cout << endl;
  return 0;
}
