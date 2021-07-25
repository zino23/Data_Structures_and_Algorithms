#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &v, int target) {
    int l = 0, r = v.size() - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;

      // Found
      if (v[mid] == target) {
        return mid;
      }

      // v[mid] in rotated
      if (v[mid] >= v[l]) {
        // l, ..., mid, ..., bgn, ..., r
        //              |
        //             target
        if (v[mid] < target) {
          l = mid + 1;
        } else {
          // l, ..., mid, ..., bgn, ..., r
          //     |                    |
          //   target              target
          if (v[l] <= target) {
            r = mid - 1;
          } else {
            l = mid + 1;
          }
        }
      } else {
        // v[mid] not in rotated
        // l, ..., bgn, ..., mid, ..., r
        //              |
        //             target
        if (v[mid] > target) {
          r = mid - 1;
        } else {
          // l, ..., bgn, ..., mid, ..., r
          //    |                    |
          //   target              target
          if (v[l] <= target) {
            r = mid - 1;
          } else {
            l = mid + 1;
          }
        }
      }
    }
    return -1;
  }
};
