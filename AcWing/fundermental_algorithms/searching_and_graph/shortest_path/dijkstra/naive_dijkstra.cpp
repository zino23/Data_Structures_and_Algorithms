#include <iostream>
#include <cstring>

using namespace std;

// the graph is composed of n nodes and m edges, and m ~ n ^ 2 
const int N = 510;
int dist[N];  // shortest distance between node 1 to node i
int g[N][N];  // use adjacent matrix to store the graph
bool st[N];  // state of each node
int n, m;

int dijkstra()
{
    // 1. set distance between node 1 and node i to inf, and set distance between node 1 and 1 to 0
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    // 2. outer loop
    // loop n times, after each loop, a node's shortest distance to node 1 is calculated
    for ( int i = 0; i < n; i ++ )
    {
        // 3. calculate the node with the shortest diatance to node 1
        int t = -1;  // the node that has the shortest distance to node 1 might be node 1
        for ( int j = 1; j <= n; j ++ )
        {
            if ( !st[j] and ( t == -1 or dist[j] < dist[t] ) )
                t = j;
        }

        // 4. mark the node as completed
        st[t] = true;

        for ( int j = 1; j <= n; j ++ )
        {
            // 5. update the distance of each node
            // note g[t][j] cannot be mistaken for g[j][t]
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    
    if ( dist[n] == 0x3f3f3f3f ) return -1;
    return dist[n];
}

int main()
{
    // set the distance between each node to inf
    memset(g, 0x3f, sizeof g);
    cin >> n >> m;
    while ( m -- )
    {
        int x, y, z;
        cin >> x >> y >> z;
        // only need to store the shortest edge
        g[x][y] = min(g[x][y], z);
    }

    cout << dijkstra() << endl;
    return 0;
}