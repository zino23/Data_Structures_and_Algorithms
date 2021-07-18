#include <stack>

using namespace std;

class MinStack {
 public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    stk_.push(x);
    if (stk_min_.empty() || stk_min_.top() >= x) stk_min_.push(x);
  }

  void pop() {
    if (stk_.empty()) return;
    int top = stk_.top();
    stk_.pop();
    if (top == stk_min_.top()) stk_min_.pop();
  }

  int top() { return stk_.top(); }

  int getMin() { return stk_min_.top(); }

 private:
  stack<int> stk_;
  stack<int> stk_min_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
