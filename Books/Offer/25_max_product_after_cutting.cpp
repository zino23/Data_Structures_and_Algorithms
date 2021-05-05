#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProductAfterCutting( int length ) {
    if ( length == 2 ) return 1;
    int r = length % 3;
    int res = 1;
    if ( r == 1 ) {
      res *= 2 * 2;
      length -= 2 * 2;
      while ( length > 0 ) {
        res *= 3;
        length -= 3;
      }
    } else if ( r == 2 ) {
      res *= 2;
      length -= 2;
      while ( length > 0 ) {
        res *= 3;
        length -= 3;
      }
    } else {
      while ( length > 0 ) {
        res *= 3;
        length -= 3;
      }
    }
    return res;
  }
};

int main() { return 0; }

