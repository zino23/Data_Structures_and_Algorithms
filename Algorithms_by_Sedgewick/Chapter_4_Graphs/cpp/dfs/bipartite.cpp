#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;
bool st[N], color[N];
int n;

void add(int x, int y)
{
    e[idx] = y, ne[idx] = h[x], h[x] = idx ++ ;
}

bool dfs(int x)
{
    st[x] = true;
    for ( int i = h[x]; i != -1; i = ne[i] )
    {
        if ( !st[e[i]] )
        {
            color[e[i]] = !color[x];
            dfs(e[i]);
        }
        else if ( color[x] == color[e[i]] ) return false;
    }
    return true;
}


int main()
{
    cin >> n;
    memset(h, -1, sizeof h);
    while ( n -- )
    {
        int x, y;
        cin >> x >> y;
        add(x, y), add(y, x);
    }

    cout << dfs(1) << endl;
    return 0;
}
