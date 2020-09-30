#include <iostream>

using namespace std;

/*
    when merge two arrays into one, the number of reverse pairs is the sum of:
    1. the reverse pairs in the left array and 
    2. the reverse pairs in the right array and
    3. the reverse pairs whose elements are in different arrays
*/

typedef long long ll;
const int N = 1e5 + 10;
int q[N];

ll reverse_pair(int q[], int l, int r)
{
    if (l >= r) return 0;  // no reverse pair if there is only one element
    int middle = l + r >> 1;
    ll num_left = reverse_pair(q, l, middle);
    ll num_right = reverse_pair(q, middle + 1, r);

    ll num_total = num_left + num_right;  // reverse pairs whose elements are in the same array

    // merge and count the number of reverse pairs whose elements are in different arrays
    int tmp[r - l + 1], i = l, j = middle + 1, k = 0;
    while (i <= middle && j <= r)
    {
        if (q[i] <= q[j]) tmp[k ++ ] = q[i ++ ];
        else
        {
            tmp[k ++ ] = q[j ++ ];
            num_total += (middle - i + 1) ;  // element in the left is larger than the right
            // *** solution2 ***: num_total ++ ; -> this is ugly
        }
    }
    
    // *** solution2 ***: if (i < middle) num_total += (middle - i) * (r - middle);

    // there are elements left in the left, and they are all bigger than the ones that are already in tmp
    while (i <= middle) tmp[k ++ ] = q[i ++ ];
    while (j <= r) tmp[k ++ ] = q[j ++ ];

    for (int i = l, k = 0; i <= r; i ++, k ++ ) q[i] = tmp[k];
    return num_total;
}

int main()
{   
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]);
    printf("Total %lld pairs", reverse_pair(q, 0, n - 1));
    return 0;
}

