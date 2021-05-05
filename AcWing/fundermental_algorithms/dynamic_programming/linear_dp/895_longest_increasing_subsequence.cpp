#include <iostream>

using namespace std;

const int N = 1e3 + 10;
int a[N], f[N];
int g[N];  // store the LIS
int n;

int main()
{
	cin >> n;
	for ( int i = 1; i <= n; i ++ ) cin >> a[i];

	for ( int i = 1; i <= n; i ++ )
	{
		f[i] = 1;  // the LIS ending with a[i] contains at least f[i]
		for ( int j = 1; j < i; j ++ )
		{
			if ( a[j] < a[i] ) f[i] = max(f[i], f[j] + 1);
			// to store the LIS, we need to store the index j which is the second last number
			// of the subsequence endign with a[i]
		}
	}

	int res = -1;
	for ( int i = 1; i <= n; i ++ ) res = max(res, f[i]);
	cout << res << endl;
	return 0;
}
