#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    unordered_map<char, char> map{{')', '('}, {']', '['}, {'}', '{'}};

    stack<char> stk;
    for (auto c : s) {
      /* Close side */
      if (map.find(c) != map.end()) {
        if (stk.empty() || stk.top() != map[c]) {
          return false;
        }
        stk.pop();
      } else {
        stk.push(c);
      }
    }
    return stk.empty();
  }
};

int main() {
  auto s = new Solution;
  s->isValid("[]()");
}