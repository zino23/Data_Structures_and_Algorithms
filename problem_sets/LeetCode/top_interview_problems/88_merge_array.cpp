#include <algorithm>
#include <cstddef>
#include <vector>
using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    sort(nums1.begin(), nums1.begin() + m);
    sort(nums2.begin(), nums2.begin() + n);
    vector<int> tmp;
    tmp.reserve(m + n);
    int i = 0, j = 0;
    while (i < m && j < n) {
      if (nums1[i] < nums2[j]) {
        tmp.push_back(nums1[i++]);
      } else {
        tmp.push_back(nums2[j++]);
      }
    }

    while (i < m) {
      tmp.push_back(nums1[i++]);
    }
    while (j < n) {
      tmp.push_back(nums2[j++]);
    }

    nums1.swap(tmp);
  }
};
