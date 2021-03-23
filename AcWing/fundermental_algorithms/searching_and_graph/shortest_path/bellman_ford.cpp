#include <iostream>
#include <cstring>

using namespace std;

int n, m, k;
const int N = 1e5 + 10;

int dist[510], last[510];

struct edges
{
    int a, b, w;
} e[N];

bool bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for ( int i = 0; i < k; i ++ )
    {
        memcpy(last, dist, sizeof dist);
        for ( int j = 0; j < m; j ++ )
        {
            auto t = e[j];
            dist[t.b] = min(dist[t.b], last[t.a] + t.w);
        }
    }
    if ( dist[n] > 0x3f3f3f3f / 2) return false;
    return true;
}

int main()
{
    cin >> n >> m >> k;
    for ( int i = 0; i < m; i ++ )
    {
        int x, y, z;
        cin >> x >> y >> z;
        e[i] = {x, y, z};
    }

    if ( bellman_ford() ) cout << dist[n];
    else cout << "impossible";
    cout << endl;
    return 0;
}
