class Solution {
 public:
  bool isPopOrder(vector<int> pushV, vector<int> popV) {
    if (pushV.size() != popV.size()) return false;
    stack<int> stk;  // After correct simulation, stk should be empty
    int p = 0;
    for (auto i : pushV) {
      stk.push(i);
      while (!stk.empty() && stk.top() == popV[p]) {
        // We can only pop from the top
        stk.pop();
        p++;
      }
    }
    return stk.empty();
  }
};
