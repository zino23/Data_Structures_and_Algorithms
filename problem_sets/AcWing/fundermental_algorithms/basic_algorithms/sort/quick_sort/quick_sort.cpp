#include <iostream>

using namespace std;

const int N = 10e5 + 10;
int q[N];

void quick_sort(int q[], int l, int r) {
  /**
   * Algorithm 1: double pointer
   */

  /* base case: only one element in the array, does not need to sort */
  if (l >= r) return;

  /**
   * initialize two pointers pointing to the left of the left boundary and to the right of the right
   * boundary
   */
  int i = l - 1, j = r + 1, x = q[(l + r) >> 1];

  /**
   * All three boundaries are to keep the index stay in bounds
   *
   * As long as the two pointers do not meet
   * 1st boundary:
   * if the condition is i <= j, when there are two elements left in the array. e.g. [1, 2]
   * first iteration, i == -1, j == 2
   * second iteration, i == 0, j == 0
   * third iteration, i == 1, j == -1 => so i when i and j meet, i.e. i == j, or i and j cross, i.e.
   * i > j, exit the main loop
   */
  while (i < j) {
    /**
     * 2nd boundary: increment i while q[i] < x
     * q[i] should be strictly smaller than x in case x is the largest number and i could go out of
     * bounds, i.e. i > r
     */

    /* move i and j to the middle at least once */
    do i++;
    while (q[i] < x);
    /**
     * 3rd boundary: decrement j while q[j] > x
     * q[j] should be strictly larger than x in case x is the smallest number and j could go out of
     * bounds, i.e. j < l
     */
    do j--;
    while (q[j] > x);

    /* if the two pointers do not meet, swap them */
    if (i < j) swap(q[i], q[j]);
  }

  /**
   * recursive sort the left side and the right side
   *
   * when use j as partition, cannot assign q[r] to x, or the program will go into a dead loop when
   * the array only contains two elements
   */

  quick_sort(q, l, j);
  quick_sort(q, j + 1, r);

  /* equivalent */
  // When use i as partition, cannot assign q[l] to x
  // quick_sort(q, l, i - 1);
  // quick_sort(q, i, r);

  /**
   * Algorithm 2: Lomuto Partition Scheme
   */

  // int x = q[l], j = l;
  // {
  // j 记录分界点最后应该处于的位置，若找到一个比 x 小的数，则分界点的位置应向右移动一位, 同时将小于
  // x 的数 q[i] 与新分界点上的数 q[++j]交换 for (int i = l + 1; i <= r; i ++ )
  //     if (q[i] < x) swap(q[ ++ j], q[i]);
  // }
  // swap(q[l], q[j]);
  // quick_sort(q, l, j - 1);
  // quick_sort(q, j + 1, r);
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", &q[i]);

  quick_sort(q, 0, n - 1);

  for (int i = 0; i < n; i++) cout << q[i] << " ";
  cout << endl;
  return 0;
}
