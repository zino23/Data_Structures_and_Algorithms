#include <vector>

using namespace std;

void qsort(vector<int> &v, int l, int r) {
  if (l >= r) {
    return;
  }

  int i = l - 1;
  int j = r + 1;
  int pivot = v[(i + j) >> 1];

  while (i < j) {
    do {
      i++;
    } while (v[i] > pivot);
    do {
      j--;
    } while (v[j] < pivot);
    if (i < j) {
      swap(v[i], v[j]);
    }
  }

  qsort(v, l, j);
  qsort(v, j + 1, r);
}
