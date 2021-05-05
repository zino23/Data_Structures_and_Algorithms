#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    if (nums.empty())
      return -1;
    int l = 0, r = nums.size() - 1; // [l, mid], [mid + 1, r]
    while (l < r) {
      int mid = (l + r) >> 1;
      if (nums[l] <= nums[mid + 1]) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return nums[l + 1];
  }
};
int main() { return 0; }

