class Solution {
 public:
  int getMissingNumber(vector<int>& nums) { return binary_search(nums); }

  int binary_search(vector<int>& nums) {
    if (nums.empty()) return 0;
    int l = 0, r = nums.size() - 1;
    int mid;
    while (l < r) {
      mid = (l + r) >> 1;
      if (nums[mid] == mid) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    if (nums[l] == l) return nums[l] + 1;
    return nums[l] - 1;
  }
};
