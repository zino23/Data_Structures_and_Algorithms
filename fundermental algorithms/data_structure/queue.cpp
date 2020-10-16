#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int q[N], hh, tt = -1;

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
            q[ ++ tt ] = x;
        }
        else if ( op == "pop" ) hh ++ ;
        else if ( op == "query" ) cout << q[hh] << endl;
        else
        {
            if ( tt >= hh) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }    
    return 0;
}