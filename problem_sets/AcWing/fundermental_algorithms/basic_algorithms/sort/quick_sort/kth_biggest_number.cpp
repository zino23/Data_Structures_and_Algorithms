#include <iostream>

using namespace std;

const int N = 100010;
int q[N];

int quick_select(int q[], int l, int r, int k) {
  if (l >= r) return q[l];

  int x = q[l + r >> 1];
  int i = l - 1, j = r + 1;
  while (i < j) {
    do {
      i++;
    } while (q[i] < x);
    do {
      j--;
    } while (q[j] > x);
    if (i < j) swap(q[i], q[j]);
  }

  int num_left = j - l + 1;
  if (k <= num_left) {
    return quick_select(q, l, j, k);
  } else {
    return quick_select(q, j + 1, r, k - num_left);
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) scanf("%d", &q[i]);

  /*     calculate kth biggest distinct number
      int i = 0, j = 1;
      while (j < k)
      {
          i ++;
          if (q[i] != q[i - 1])
          {
              j ++;
              while (q[i] == q[i - 1]) i ++;
          }
      }
      cout << q[i] << endl; */

  cout << quick_select(q, 0, n - 1, k);
}
