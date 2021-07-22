#include <deque>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    nums.insert(nums.begin(), 0);
    vector<long long> pre_sum(nums.size(), 0);
    // Store idx instead of value to conveniently limit the size of subarray
    deque<int> q{0};

    const int min = -1e5 - 10;
    long long res = min;

    // May be provided as limit of size of subarray
    // No limit here, set to the size of nums
    const int m = nums.size();

    for (int i = 1; i < nums.size(); i++) {
      // Calc pre_sum
      pre_sum[i] = pre_sum[i - 1] + nums[i];
      // The size of subarray is larger than m, pop front
      if (i - q.front() > m) q.pop_front();
      // Update res
      res = max(res, pre_sum[i] - pre_sum[q.front()]);
      // Insert pre_sum[i] into monotic queue q
      while (!q.empty() && q.back() >= pre_sum[i]) q.pop_back();
      q.push_back(i);
    }
    return res;
  }

  int maxSubArrayOld(vector<int>& nums) {
    nums.insert(nums.begin(), 0);
    vector<int> pre_sum(nums.size(), 0);
    deque<int> q{pre_sum[0]};
    pre_sum[1] = nums[1];
    int res = pre_sum[1];

    for (int i = 2; i < nums.size(); i++) {
      pre_sum[i] = pre_sum[i - 1] + nums[i];
      while (!q.empty() && q.back() >= pre_sum[i - 1]) q.pop_back();
      q.push_back(pre_sum[i - 1]);
      res = max(res, pre_sum[i] - q.front());
    }
    return res;
  }
};
