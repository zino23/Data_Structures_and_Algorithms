#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int stk[N], hh;

int main()
{
    int n, x;
    cin >> n;
    while ( n -- )
    {
        cin >> x;
        while ( hh && stk[hh] >= x ) hh -- ;
        if ( hh ) cout << stk[hh] << ' ';
        else cout << "-1" << ' ';
        stk[ ++ hh ] = x;
    }
    return 0;
}