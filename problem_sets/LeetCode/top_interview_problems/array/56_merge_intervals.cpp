#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &lhs, vector<int> &rhs) {
           if (lhs[0] != rhs[0]) {
             return lhs[0] < rhs[0];
           } else {
             return lhs[1] <= rhs[1];
           }
         });
    vector<vector<int>> res;
    int l = intervals[0][0], r = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
      // Has overlap
      if (intervals[i][0] <= r) {
        r = max(r, intervals[i][1]);
      } else {
        res.push_back(vector<int>{l, r});
        l = intervals[i][0];
        r = intervals[i][1];
      }
    }
    res.push_back(vector<int>{l, r});
    return res;
  }
};
