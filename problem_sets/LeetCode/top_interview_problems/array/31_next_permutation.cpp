#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &v) {
    /**
     * Need to exchange v[i] with v[j], with cond i < j && v[i] < v[j]
     * i needs to be as large as possible
     * v[j] needs to be as small as possible
     */
    int i = v.size() - 1, j = -1;
    for (; i > 0; i--) {
      /* Found a reverse pair v[i - 1], v[i] with v[i - 1] < v[i] */
      if (v[i - 1] < v[i]) {
        j = i;
        /* Search for j so that v[i - 1] < v[j] && v[j] is as small as possible
         */
        while (j + 1 < v.size() && v[i - 1] < v[j + 1]) {
          j++;
        }
        swap(v[i - 1], v[j]);
        reverse(v.begin() + i, v.end());
        return;
      }
    }

    /* v is the largest permutation */
    reverse(v.begin(), v.end());
  }
};
