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
  int lowbit( int n ) { return n & -n; }

  int NumberOf1( int n ) {
    int res = 0;
    // if ( n >= 0 ) {
    //   while ( n > 0 ) {
    //     n -= lowbit( n );
    //     res++;
    //   }
    // } else {
    //   while ( n < 0 ) {
    //     n -= lowbit( n );
    //     res++;
    //   }
    // }

    // or better: change the interpretation of the bits of n
    unsigned int _n = n;
    while ( _n > 0 ) {
      _n -= lowbit( _n );
      res++;
    }
    return res;
  }
};
int main() { return 0; }

