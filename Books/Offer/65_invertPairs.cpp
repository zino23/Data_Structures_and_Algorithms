#include <vector>

using namespace std;

class Solution {
public:
  // Return number of invert pairs in [l, r]
  int merge_sort(vector<int> &nums, int l, int r) {
    if (l == r) {
      return 0;
    }
    int res = 0;
    int mid = (l + r) >> 1;
    res += merge_sort(nums, l, mid);
    res += merge_sort(nums, mid + 1, r);
    int i = l, j = mid + 1;
    vector<int> tmp;
    while (i <= mid && j <= r) {
      if (nums[i] > nums[j]) {
        tmp.push_back(nums[j]);
        int size = mid - i + 1;
        res += size;
        j++;
      } else {
        tmp.push_back(nums[i]);
        i++;
      }
    }
    while (i <= mid) {
      tmp.push_back(nums[i++]);
    }

    while (j <= r) {
      tmp.push_back(nums[j++]);
    }
    copy(tmp.begin(), tmp.end(), nums.begin() + l);
    return res;
  }
  int inversePairs(vector<int> &nums) {
    if (nums.empty())
      return 0;
    return merge_sort(nums, 0, nums.size() - 1);
  }
};
