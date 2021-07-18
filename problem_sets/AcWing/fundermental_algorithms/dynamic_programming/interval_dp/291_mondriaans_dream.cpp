#include <iostream>
#include <cstring>

using namespace std;

typedef long long LL;
const int N = 4e3;
const LL M = 1e8;
LL f[N][N];
bool st[N];
int cnt;

int main()
{
	int n, m;
	while ( cin >> n >> m, n || m )
	{
		memset(f, 0, sizeof f);
		memset(st, true, sizeof st);
		for ( int i = 0; i < 1 << n; i ++ )
		{
			cnt = 0;
			for ( int j = 0; j < n; j ++ )
			{
				if ( i >> j & 1 )
				{
					if ( cnt % 2 == 1 ) st[i] = false;
				}
				else cnt ++ ;
			}

			// case when n & 1 == 1, need to test cnt
			if ( cnt & 1 ) st[i] = false;
		}

		// place rectangle through column 0:m - 1
		// but consider how to place horizontal rectangle with column 1
		// so column 0 has zero rectangles, i.e. the initial condition is f[0][0] == 1
		// and we want to calculate f[m][0]
		f[0][0] = 1;
		for ( int i = 1; i <= m; i ++ )
		{
			for ( int j = 0; j < 1 << n; j ++ )
			{
				for ( int k = 0; k < 1 << n; k ++ )
				{
					if ( ( j & k ) == 0 && st[j | k] )
						f[i][j] += f[i - 1][k];
				}
			}
		}

		cout << f[m][0] << endl;
	}
	return 0;
}
