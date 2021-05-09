class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    // int sum = 0;
    // int res = INT_MIN;
    // for (auto i : nums) {
    //   if (sum <= 0)
    //     sum = i;
    //   else
    //     sum += i;
    //   res = max(res, sum);
    // }

    // 子数组最小长度
    int k = 1;
    // 开始搜索前缀和数组的位置
    int last = -1;
    int min_pre_sum = INT_MAX;
    int res = INT_MIN;
    vector<int> pre_sum(nums.size() + 1);
    for (int i = 0; i < nums.size(); i++) {
      pre_sum[i + 1] = pre_sum[i] + nums[i];
      // i - st + 1 == k
      // 搜索停止位置
      int st = i + 1 - k;
      // 搜索最小前缀和数组，从上一次停止的位置 last 开始
      while (last < st) {
        min_pre_sum = min(min_pre_sum, pre_sum[last + 1]);
        last++;
      }
      res = max(res, pre_sum[i + 1] - min_pre_sum);
    }
    return res;
  }

  int maxSubArrayLeastLen(vector<int> &nums, int k) {
    int last = -1;
    int res = INT_MIN;
    int min_pre_sum = INT_MAX;
    vector<int> pre_sum(nums.size() + 1);
    for (int i = 0; i < nums.size(); i++) {
      pre_sum[i + 1] = pre_sum[i] + nums[i];
      // i - st + 1 == k
      int st = i + 1 - k;
      while (last < st) {
        min_pre_sum = min(min_pre_sum, pre_sum[last + 1]);
        last++;
      }
      res = max(res, pre_sum[i + 1] - min_pre_sum);
    }
    return res;
  }
};
