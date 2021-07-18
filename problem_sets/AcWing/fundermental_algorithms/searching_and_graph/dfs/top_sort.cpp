#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;
int d[N];
int q[N], hh, tt = -1;
int n, m;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

// the graph will still be a DAG if its vertexes that has 0 indegrees are removed
bool top_sort()
{
    for ( int i = 1; i <= n; i ++ )
    {
        if ( !d[i] ) q[ ++ tt ] = i;
    }
    
    while ( tt >= hh )
    {
        int t = q[hh ++ ];
        for ( int i = h[t]; i != -1; i = ne[i] )
        {
            d[e[i]] -- ;
            if ( !d[e[i]] ) q[ ++ tt ] = e[i];
        }
    }
    
    return tt == n - 1;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while ( m -- )
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        d[y] ++ ;
    }
    
    if ( !top_sort() ) cout << -1;
    else
    {
        for ( int i = 0; i < n; i ++ )
        {
            cout << q[i] << ' ';
        }
    }
    cout << endl;
    return 0;
}