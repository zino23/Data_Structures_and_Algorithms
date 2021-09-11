#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &v, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < v.size(); i++) {
      if (map.find(target - v[i]) == map.end()) {
        map[v[i]] = i;
      } else {
        return {map[target - v[i]], i};
      }
    }
    return {-1, -1};
  }
};
