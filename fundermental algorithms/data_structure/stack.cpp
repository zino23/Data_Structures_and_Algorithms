#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int stk[N], hh;

int main()
{
    int m, x;
    cin >> m;
    while ( m -- )
    {
        string op;
        cin >> op;
        if ( op == "push" )
        {
            cin >> x;
            stk[ ++ hh ] = x;
        }
        else if ( op == "pop" ) hh -- ;
        else if ( op == "empty")
        {
            if ( hh > 0 ) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
        else cout << stk[hh] << endl;
    }
    return 0;
    
}