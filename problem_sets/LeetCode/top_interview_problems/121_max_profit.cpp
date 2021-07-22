#include <deque>
#include <vector>
using namespace std;

class Solution {
  int maxProfit(vector<int> &prices) {
    // Use deque to make a monotic queue
    deque<int> q{prices[0]};
    int res = 0;

    // Calculate all max profits sold at i
    for (int i = 1; i < prices.size(); i++) {
      // Update res (res >= 0)
      res = max(res, prices[i] - q.front());

      // Update monotic queue
      while (!q.empty() && q.back() >= prices[i]) {
        q.pop_back();
      }

      q.push_back(prices[i]);
    }

    // Cos min(res) is 0, following corner cases have all been considered, just
    // return
    // 1. prices only has one element
    // 2. profit is negative
    return res;
  }
};
