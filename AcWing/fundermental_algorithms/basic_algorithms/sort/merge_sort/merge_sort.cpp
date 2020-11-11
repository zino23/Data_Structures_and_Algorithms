#include <iostream>

using namespace std;

const int N = 100010;
int q[N], tmp[N];

void merge_sort(int q[], int l, int r)
{
    // base case
    if (l >= r) return;

    // divide
    int mid = (l + r) >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    // int tmp[r - l + 1];
    int i = l, j = mid + 1, k = 0;

    // merge
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j]) tmp[k ++ ] = q[i ++ ];
        else tmp[k ++ ] = q[j ++ ];
    }
    
    while (i <= mid) tmp[k ++ ] = q[i ++];
    while (j <= r) tmp[k ++ ] = q[j ++ ];
    
    for (int i = l, k = 0; i <= r; i ++, k ++ ) q[i] = tmp[k];
}

int main()
{
    // int n;
    // cin >> n;
    for (int i = 0; i < 3; i ++ ) scanf("%d", &q[i]);
    int q[] = {3, 2, 1};
    merge_sort(q, 0, 3 - 1);
    
    for (int i = 0; i < 3; i ++ ) cout << q[i] << " ";
    cout << endl;

    return 0;
}