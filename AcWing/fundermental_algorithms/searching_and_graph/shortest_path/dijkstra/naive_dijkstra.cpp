#include <iostream>
#include <cstring>

using namespace std;

const int N = 510;
int g[N][N];
int dist[N];
bool st[N];
int n, m;

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    for ( int i = 0; i < n; i ++ )
    {
        int t = -1;
        for ( int j = 1; j <= n; j ++ )
        {
            if ( !st[j] && ( t == -1 || dist[j] < dist[t] ))
                t = j;
        }
        
        st[t] = true;
        
        for ( int j = 1; j <= n; j ++ )
        {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    
    if ( dist[n] == 0x3f3f3f3f ) return -1;
    return dist[n];
}

int main()
{
    memset(g, 0x3f, sizeof g);
    cin >> n >> m;
    while ( m -- )
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
    }
    
    cout << dijkstra() << endl;
    return 0;
}