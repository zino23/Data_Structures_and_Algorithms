#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const int NUM = static_cast<int>(pow(2.0, 31.0));

class Solution {
public:
  int reverse(int x) {
    vector<int> high, low;
    int a = NUM - 1;
    while (a > 0) {
      high.push_back(a % 10);
      a /= 10;
    }
    std::reverse(high.begin(), high.end());

    a = NUM;
    while (a > 0) {
      low.push_back(a % 10);
      a /= 10;
    }
    std::reverse(low.begin(), low.end());

    int res = 0;
    return res;
  }
};
