#include <vector>

using namespace std;

class Solution {
public:
  bool canAttendMeetings(vector<vector<int>> &intervals) {
    if (intervals.empty()) {
      return true;
    }

    sort(intervals.begin(), intervals.end());
    int r = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] < r) {
        return false;
      } else {
        r = intervals[i][1];
      }
    }
    return true;
  }
};
