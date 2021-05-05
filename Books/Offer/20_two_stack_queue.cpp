#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class MyQueue {
 public:
  stack<int> stk_push, stk_pop;

  /** Initialize your data structure here. */
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push( int x ) { stk_push.push( x ); }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    if ( stk_pop.empty() && stk_push.empty() ) {
      throw runtime_error( "The queue is empty!" );
    }

    if ( stk_pop.empty() ) {
      while ( !stk_push.empty() ) {
        // cannot push to stk_pop if it has elements
        int x = stk_push.top();
        stk_push.pop();
        stk_pop.push( x );
      }
    }
    int x = stk_pop.top();
    stk_pop.pop();
    return x;
  }

  /** Get the front element. */
  int peek() {
    if ( stk_pop.empty() && stk_push.empty() ) {
      throw runtime_error( "The queue is empty!" );
    }

    if ( stk_pop.empty() ) {
      while ( !stk_push.empty() ) {
        int x = stk_push.top();
        stk_push.pop();
        stk_pop.push( x );
      }
    }
    return stk_pop.top();
  }

  /** Returns whether the queue is empty. */
  bool empty() { return stk_pop.empty() && stk_push.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
int main() { return 0; }
