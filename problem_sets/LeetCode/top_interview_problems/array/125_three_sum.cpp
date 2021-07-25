#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &v) {
    if (v.size() < 3) {
      return {};
    }

    sort(v.begin(), v.end());
    vector<vector<int>> res;
    for (int k = 0; k <= v.size() - 3; k++) {
      // Note: if i starts at 0, there will be duplicates
      int i = k + 1, j = v.size() - 1;
      int target = -v[k];
      while (i < j) {
        if (v[i] + v[j] < target) {
          i++;
        } else if (v[i] + v[j] > target) {
          j--;
        } else {
          // Found an answer
          res.push_back(vector<int>{v[i], v[j], -target});

          // Move i and j to the end of repeating numbers
          while (i + 1 < v.size() && v[i] == v[i + 1]) {
            i++;
          }

          while (j - 1 >= 0 && v[j] == v[j - 1]) {
            j--;
          }

          // Move to the non-repeating number
          i++;
          j--;
        }
      }

      // Move k to the end of repeating numbers
      while (k + 1 <= v.size() - 3 && v[k] == v[k + 1]) {
        k++;
      }
    }
    return res;
  }
};
