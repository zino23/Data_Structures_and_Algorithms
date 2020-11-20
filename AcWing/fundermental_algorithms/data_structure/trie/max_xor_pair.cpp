#include <iostream>

using namespace std;

const int N = 1e5 + 10, M = 1e5 * 32;
int a[N], son[M][2], idx;

int main()
{
    int n;
    cin >> n;
    // use trie to store the binary repr of each number
    for ( int i = 0; i < n; i ++ )
    { 
        cin >> a[i];
        int p = 0;
        for ( int j = 30; ~j; j -- )
        {
            int u = (a[i] >> j) & 1;
            if ( !son[p][u]) son[p][u] =  ++ idx;
            p = son[p][u];
        }
    }

    // query
    int res = 0, tmp = 0;
    for ( int i = 0; i < n; i ++ )
    {
        int p = 0;
        for ( int j = 30; ~j; j -- )
        {
            int u = (a[i] >> j) & 1;
            if ( son[p][!u] )
            {
                p = son[p][!u];
                tmp += 1 << j;
            }
            else p = son[p][u];
        }
        res = max(res, tmp);
        tmp = 0;
    }
    cout << res << endl;
    return 0;
}
