class Solution {
public:
  int moreThanHalfNum_Solution(vector<int> &nums) {
    int cnt = 1;
    int val = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (cnt == 0) {
        val = nums[i];
        cnt = 1;
        continue;
      }

      if (nums[i] == val) {
        cnt++;
      } else {
        cnt--;
      }
    }
    return val;
  }
};
