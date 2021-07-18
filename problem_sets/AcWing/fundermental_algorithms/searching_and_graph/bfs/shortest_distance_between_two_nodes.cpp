#include <iostream>
#include <cstring>

using namespace std;

int n, m;
const int N = 1e5 + 10;
int q[N], e[N], ne[N], idx, tt = -1, hh = 0;
int h[N];
int d[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int bfs(int start, int end)
{
    memset(d, -1, sizeof d);
    q[ ++ tt] = start;
    d[start] = 0;
    
    while ( tt >= hh )
    {
        int u = q[hh ++ ];
        for ( int i = h[u]; i != -1; i = ne[i] )
        {
            int j = e[i];
            if ( d[j] == -1 )
            {
                q[ ++ tt] = j;
                d[j] = d[u] + 1;
            }
        }
    }
    return d[end];
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while ( m -- )
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    
    cout << bfs(1, n) << endl;
    return 0;
}