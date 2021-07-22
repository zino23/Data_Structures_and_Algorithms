#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  int trap(vector<int>& height) {
    /* Store idx instead of val to calc width conveniently */
    stack<int> stk;
    int res = 0;

    int last_height = 0;
    for (int i = 0; i < height.size(); i++) {
      /**
       * Meet a bar higher than stk.top(), can hold water now
       *
       * Deal with bars shorter than height[i] first
       */
      while (!stk.empty() && height[stk.top()] < height[i]) {
        int t = stk.top();
        stk.pop();
        int l = i - t - 1;
        int h = height[t] - last_height;
        res += l * h;
        last_height = height[t];
      }

      /* If stk is not empty, stk.top() is higher than height[i] */
      if (!stk.empty()) {
        int t = stk.top();
        int l = i - t - 1;
        int h = height[i] - last_height;
        res += l * h;
      }
      stk.push(i);
    }
    return res;
  }
};

int main() {
  vector<int> bar{4, 2, 0, 3, 2, 5};
  Solution s;
  cout << s.trap(bar) << endl;
  return 0;
}
