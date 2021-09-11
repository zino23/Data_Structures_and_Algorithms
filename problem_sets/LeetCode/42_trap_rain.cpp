#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    /**
     * Use monotic stack to find the first bar which is higher than the current
     * bar from left. Calc answer during this process
     *
     * Note: store index to conveniently calc width
     */
    stack<int> stk;
    int res = 0;
    for (int i = 0; i < height.size(); i++) {
      int last_height = 0;

      /**
       * Found a bar not lower than the bar at stk.top(), can hold water now
       */
      while (!stk.empty() && height[stk.top()] <= height[i]) {
        int t = stk.top();
        stk.pop();
        int width = i - t - 1;
        int h = height[t] - last_height;
        res += width * h;
        last_height = height[t];
      }

      /**
       * The bar at stk.top() is higher than height[i]
       */
      if (!stk.empty()) {
        int t = stk.top();
        int width = i - t - 1;
        int h = height[i] - last_height;
        res += width * h;
      }

      stk.push(i);
    }
    return res;
  }
};
