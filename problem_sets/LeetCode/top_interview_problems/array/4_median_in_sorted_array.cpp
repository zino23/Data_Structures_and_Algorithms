#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  // O(logn)
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int len = nums1.size() + nums2.size();
    if (len % 2 == 0) {
      int l = findKth(nums1, 0, nums2, 0, len / 2);
      int r = findKth(nums1, 0, nums2, 0, len / 2 + 1);
      return (l + r) / 2.0;
    } else {
      return findKth(nums1, 0, nums2, 0, len / 2 + 1);
    }
  }

  // Find kth element starting at @i in @v1 and @j in @v2
  int findKth(vector<int>& v1, int i, vector<int>& v2, int j, int k) {
    // Make sure the searchable size of v1 is smaller than that ofv2
    if (v1.size() - i > v2.size() - j) {
      return findKth(v2, j, v1, i, k);
    }

    // Base case
    if (k == 1) {
      // v1 is empty, return the first of v2
      // Note: v2 will always have enough elements
      if (v1.size() == i) {
        return v2[j];
      } else {
        return min(v1[i], v2[j]);
      }
    }

    // If v1 is empty, return elemnts in v2 directly, otherwise v1[ei] will cause address error
    if (i == v1.size()) {
      // ej - j + 1 = k
      return v2[k + j - 1];
    }

    // Note: k / 2 may be larger than v1.size() - i
    // ei - i + 1 = k / 2
    int ei = min(i + k / 2 - 1, (int)v1.size() - 1);
    // ej - j + 1 = k - k / 2;
    int ej = k - k / 2 + j - 1;

    if (v1[ei] < v2[ej]) {
      return findKth(v1, ei + 1, v2, j, k - (ei - i + 1));
    } else {
      return findKth(v1, i, v2, ej + 1, k - (ej - j + 1));
    }
  }

  // O(n)
  double findMedianSortedArraysMerge(vector<int>& nums1, vector<int>& nums2) {
    int len = nums1.size() + nums2.size();
    int i = 0, j = 0, cnt = 0;
    vector<int> res;
    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] <= nums2[j]) {
        res.push_back(nums1[i++]);
      } else {
        res.push_back(nums2[j++]);
      }
      cnt++;
      if (cnt == len / 2 + 1) {
        break;
      }
    }

    while (cnt < len / 2 + 1 && i < nums1.size()) {
      res.push_back(nums1[i++]);
      cnt++;
    }

    while (cnt < len / 2 + 1 && j < nums2.size()) {
      res.push_back(nums2[j++]);
      cnt++;
    }

    if (len % 2 == 0) {
      return (res[cnt - 1] + res[cnt - 2]) / 2.0;
    } else {
      return res[cnt - 1];
    }
  }

  // O(nlogn)
  double findMedianSortedArraysSort(vector<int>& nums1, vector<int>& nums2) {
    copy(nums1.begin(), nums1.end(), back_inserter(nums2));
    sort(nums2.begin(), nums2.end());
    int len = nums2.size();
    if (len % 2 == 0) {
      return (nums2[len / 2] + nums2[len / 2 - 1]) / 2.0;
    } else {
      return nums2[len / 2];
    }
  }
};

int main() {
  auto s = new Solution;
  auto v1 = vector<int>();
  auto v2 = vector<int>{2, 3};
  cout << s->findMedianSortedArrays(v1, v2) << endl;
  return 0;
}
