class MinStack {
 public:
  /** initialize your data structure here. */
  stack<int> stk;
  stack<int> stkMin;
  MinStack() {}

  void push(int x) {
    stk.push(x);
    if (stkMin.empty() || x <= stkMin.top()) {
      stkMin.push(x);
    }
  }

  void pop() {
    int x = stk.top();
    stk.pop();
    if (x == stkMin.top()) stkMin.pop();
  }

  int top() { return stk.top(); }

  int getMin() { return stkMin.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
