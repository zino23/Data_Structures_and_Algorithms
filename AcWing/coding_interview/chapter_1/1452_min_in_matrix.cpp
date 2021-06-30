// Forward declaration of queryAPI.
// int query(int x, int y);
// return int means matrix[x][y].

#include <vector>

using namespace std;

class Solution {
public:
  vector<int> getMinimumValue(int n) {
    using LL = long long;
    const LL INF = 1e16;
    int l = 0, r = n - 1;
    while (l < r) {
      int mid = (l + r) >> 1;
      LL v_min = INF;
      int row = -1;
      for (int i = 0; i < n; i++) {
        int tmp = query(i, mid);
        if (tmp < v_min) {
          v_min = tmp;
          row = i;
        }
      }

      LL left = (mid == 0) ? INF : query(row, mid - 1);
      LL right = (mid == n - 1) ? INF : query(row, mid + 1);
      if (v_min < left && v_min < right) {
        return {row, mid};
      } else if (v_min < left) {
        // go right
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    int row = -1;
    LL v_min = INF;
    for (int i = 0; i < n; i++) {
      int tmp = query(i, l);
      if (tmp < v_min) {
        row = i;
        v_min = tmp;
      }
    }
    return {row, l};
  }
};
