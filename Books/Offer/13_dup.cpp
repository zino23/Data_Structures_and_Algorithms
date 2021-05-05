#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
      if ( nums.empty() ) return -1;
      unordered_map<int, bool> map;
      int size = nums.size();
      bool found = false;
      int ans = 0;
      for ( auto x : nums ) {
        if ( x < 0 || x >= size ) {
          return -1;
        }
        if ( map.find( x ) == map.end() ) {
          map[x] = true;
        } else {
          found = true;
          ans = x;
        }
      }
      if ( found ) {
        return ans;
      }
      return -1;
    }
};

int main() {
  return 0;
}
