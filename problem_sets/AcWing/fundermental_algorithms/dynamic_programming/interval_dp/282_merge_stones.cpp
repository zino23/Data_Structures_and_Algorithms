#include <iostream>

using namespace std;

const int N = 310;
int a[N], s[N];
int f[N][N];
const int INF = 1e8;

int main() {
  int n;
  cin >> n;
  for ( int i = 1; i <= n; i++ ) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
  }

  // f[i][j]: merge stones from i to j
  // f[i][j] = max(f[i][j - 1] + s[j] - s[i - 1], f[i + 1][j] + s[j] - s[i - 1])

  // make sure the state which transfers to the current state has been
  // calculated, iterate over the length of interval
  // when length == 1, the cost is 0
  for ( int len = 2; len <= n; len++ ) {
    // ed - st + 1 == i
    for ( int st = 1; st <= n + 1 - len; st++ ) {
      int ed = st + len - 1;
      f[st][ed] = INF;
      for ( int i = st; i <= ed - 1; i++ ) {
        f[st][ed] =
            min( f[st][ed], f[st][i] + f[i + 1][ed] + s[ed] - s[st - 1] );
      }
    }
  }

  cout << f[1][n] << endl;
  return 0;
}
