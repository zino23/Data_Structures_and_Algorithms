#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;
int st[N];
int n, m;
int id[N], cnt;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int x)
{
    st[x] = true;
    id[x] = cnt;
    for ( int i = h[x]; i != -1; i = ne[i] )
    {
        if ( !st[e[i]] ) dfs(e[i]);
    }
}

int connected_components()
{
    for ( int i = 1; i <= n; i ++ )
    {
        if ( !st[i] )
        {
            dfs(i);
            cnt ++ ;
        }
    }
    return cnt;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while ( m -- )
    {
        int x, y;
        cin >> x >> y;
        add(x, y), add(y, x);
    }
    cout << connected_components() << endl;
    return 0;
}
