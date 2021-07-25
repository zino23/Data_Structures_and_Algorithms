#include <vector>

using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int> &v, int target) {
    for (int i = 0; i < v.size(); i++) {
      // i is the beginning
      if (v[i] == target) {
        int j = i;
        // j is the end
        while (j + 1 < v.size() && v[j] == v[j + 1]) {
          j++;
        }
        return {i, j};
      }
    }
    return {-1, -1};
  }
};
