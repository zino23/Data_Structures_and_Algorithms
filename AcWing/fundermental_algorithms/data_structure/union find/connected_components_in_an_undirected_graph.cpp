#include <iostream>

using namespace std;

const int N = 1e5 + 10;
// cnt[u] have meaning only when u is root node
int p[N], n, m, cnt[N];

int find(int x)
{
    if ( p[x] != x ) p[x] = find(p[x]);
    return p[x];
}

int main()
{   
    cin >> n >> m;
    for ( int i = i; i <= n; i ++ )
    {
        p[i] = i;
        cnt[i] = 1;
    }

    string op;
    int a, b, x, y;
    while ( m -- )
    {
        cin >> op;
        if ( op == "C" )
        {
            cin >> a >> b;
            x = find(a), y = find(b);
            if ( x != y )
            {
                p[x] = y;
                cnt[y] += cnt[x];
            }
        }
        else if ( op == "Q1" )
        {
            cin >> a >> b;
            if ( find(a) == find(b) ) puts("Yes");
            else puts("No"); 
        }
        else
        {
            cin >> a;
            cout << cnt[find(a)] << endl;
        }
    }
    return 0;
}
