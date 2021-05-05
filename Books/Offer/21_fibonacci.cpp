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
  int Fibonacci( int n ) {
    unordered_map<int, int> map;
    map[1] = 1, map[2] = 1;
    if ( n <= 2 ) return map[n];
    for ( int i = 3; i <= n; i++ ) {
      map[i] = map[i - 1] + map[i - 2];
    }
    return map[n];
  }
};

int main() { return 0; }

