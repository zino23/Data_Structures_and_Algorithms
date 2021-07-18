#include <iostream>

using namespace std;

const int N = 510;
const int INF = 1e6;
int f[N][N], v[N][N];

int main()
{
	int n;
	cin >> n;

	// in order not to consider the boundary conditions
	for ( int i = 1; i <= n; i ++ )
	{
		f[i][0] = f[i][i + 1] = -INF;
	}

	cin >> f[1][1];
	for ( int i = 2; i <= n; i ++ )
	{
		for ( int j = 1; j <= i; j ++ )
		{
			cin >> v[i][j];
			f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + v[i][j];
		}
	}

	int res = 0;
	for ( int i = 1; i <= n; i ++ )
	{
		res = max(res, f[n][i]);
	}
	cout << res << endl;
	return 0;
}
