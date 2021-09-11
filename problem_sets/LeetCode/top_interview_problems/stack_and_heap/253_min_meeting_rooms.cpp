#include <functional>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int minMeetingRooms(vector<vector<int>> &intervals) {
    priority_queue<int, vector<int>, greater<int>> q;
    sort(intervals.begin(), intervals.end());
    for (auto v : intervals) {
      if (q.empty()) {
        q.push(v[1]);
      } else {
        int t = q.top();
        if (t <= v[0]) {
          q.pop();
          q.push(v[1]);
        } else {
          q.push(v[1]);
        }
      }
    }
    return q.size();
  }
};
