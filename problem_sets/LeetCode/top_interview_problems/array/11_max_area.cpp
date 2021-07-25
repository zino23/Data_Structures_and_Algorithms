#include <vector>
using namespace std;

class Solution {
public:
  // O(n)
  int maxArea(vector<int> &height) {
    int i = 0, j = height.size() - 1;
    int res = 0;
    while (i < j) {
      int l = j - i;
      int h = min(height[i], height[j]);
      res = max(res, l * h);
      if (height[i] <= height[j]) {
        i++;
      } else {
        j--;
      }
    }
    return res;
  }
};
