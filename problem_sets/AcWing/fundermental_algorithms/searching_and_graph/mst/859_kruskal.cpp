#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;
int p[N];

struct Edge
{
	int a, b, w;
	bool operator<(Edge &e) 
	{
		return w < e.w;
	}
}edges[M];

int find(int x)
{
	if ( p[x] != x ) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	int n, m;
	cin >> n >> m;
	for ( int i = 0; i < m; i ++ )
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges[i] = { a, b, c };
	}
	sort(edges, edges + m);
	
	for ( int i = 0; i < n; i ++ )
	{
		p[i] = i;
	}
	
	int res = 0, cnt = 0;
	for ( auto e : edges )
	{
		int a = find(e.a), b = find(e.b);
		if ( a != b )
		{
			p[a] = b;
			res += e.w;
			cnt ++ ;	
		}		
	}
	
	if ( cnt == n - 1 ) cout << res;
	else cout << "impossible";
	cout << endl;
	return 0;
}
