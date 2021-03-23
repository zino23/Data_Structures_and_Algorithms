#include <iostream>
#include <cstring>

const int N = 510, INF = 0x3f3f3f3f;
int g[N][N];
int n, m;
bool st[N];
int dist[N];

using namespace std;

int prim()
{
	int res = 0;
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;

	for ( int i = 0; i < n; i ++ )
	{
		int t = -1; // in the first loop, vertex 1 is selected
		for ( int j = 1; j <= n; j ++ )
		{
			if ( !st[j] && ( t == -1 || dist[j] < dist[t] ) )
			{
				 t = j;
			}
		}

        st[t] = true;
		if ( dist[t] == INF ) return INF;  // cannot find a mst
		else res += dist[t];

		for ( int j = 1; j <= n; j ++ )
		{
			dist[j] = min(dist[j], g[t][j]);  // given any vertex x, dist[x] will only change
			// only when there is an edge t->x
		}
	}
	return res;
}


int main()
{
	cin >> n >> m;
	memset(g, 0x3f, sizeof g);
	while ( m -- )
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[b][a] = g[a][b] = min(g[a][b], c);
	}

	int res = prim();
	if ( res == 0x3f3f3f3f ) cout << "impossible";
	else cout << res;
	cout << endl;
	return 0;

}
