#include <iostream>
#include <vector>

using namespace std;

/* Size of the heap */
int s;

/**
 * Sink element whose index in the underlying container is @idx to the proper
 * position
 */
void down(vector<int> &v, int idx) {
  /* Until sink to bottom or is at a feasible position */
  while (idx * 2 <= s) {
    int u = idx * 2;
    /**
     * Find the smaller child
     * Note: u + 1 may be larger than s
     */
    if (u < s && v[u + 1] < v[u]) {
      u++;
    }

    /* Check if need to sink */
    if (v[idx] > v[u]) {
      swap(v[idx], v[u]);
      idx = u;
    } else {
      break;
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  s = n;
  vector<int> v;
  v.reserve(n + 1);

  /* First slot is not used to store the heap */
  v.push_back(-1);
  int a;
  while (cin >> a) {
    v.push_back(a);
  }

  /**
   * Make heap
   *
   * Sink from second to last row, hence,
   * Second to last needs total n/2 * 1 sink
   * Third to last needs total n/4 * 2 sink
   * ...
   * The total # of sink to build a heap is n*(1/2+(1/2)^2+(1/2)^3+...) ~ O(n)
   */
  for (int i = s / 2; i >= 1; i--) {
    down(v, i);
  }

  while (m--) {
    cout << v[1] << ' ';
    s = v.size() - 1;
    v[1] = v[s];
    v.pop_back();
    down(v, 1);
    cout << m << ": ";
    for (int i = 1; i < v.size(); i++) {
      cout << v[i] << ' ';
    }
    cout << endl;
  }
  return 0;
}
