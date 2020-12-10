#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;
int st[N];
int n;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

// v is the current vertex to be visited, u is the parent of v
bool dfs(int v, int u)
{   
    st[v] = true;
    for ( int i = h[v]; i != -1; i = ne[i] )
    {
        if ( !st[e[i]] ) dfs(e[i], v);
        else if ( e[i] != u ) return true;
    }
    return false;
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

    cout << dfs(1, 1) << endl;
    return 0;
}
