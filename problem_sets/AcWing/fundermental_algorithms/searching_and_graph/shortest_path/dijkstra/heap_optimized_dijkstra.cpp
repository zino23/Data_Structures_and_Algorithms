#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e6 + 10;
int dist[N];
int h[N], e[N], ne[N], w[N], idx;
bool st[N];
int n, m;

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++ ;
}



int dijkstra()
{
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    while ( heap.size() )
    {
        auto t = heap.top();
        int distance = t.first, ver = t.second;
        heap.pop();
        
        if ( st[ver] ) continue;
        st[ver] = true;
        
        for ( int i = h[ver]; i != -1; i = ne[i] )
        {
            int j = e[i];
            if ( distance + w[i] < dist[j] )
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    
    if ( dist[n] == 0x3f3f3f3f ) return -1;
    return dist[n];
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while ( m -- )
    {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    cout << dijkstra() << endl;
    return 0;
}