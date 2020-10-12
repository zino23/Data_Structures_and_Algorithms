#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N], s[N];

int main()
{
    int n;
    cin >> n;
    for ( int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

    int res = 0;
    for (int i = 0, j = 0; i < n; i ++ )
    {
        s[a[i]] ++ ;
        while (j <= i && s[a[i]] > 1)
        {
            s[a[j]] -- ;
            j ++ ;
        }
        res = max(res, i - j + 1);
    }

    return 0;
}