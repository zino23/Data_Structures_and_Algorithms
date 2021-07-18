#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
const int N = 1e5 + 10;
vector<int> res[N];

int main()
{
	int n;
	cin >> n;
	for ( int i = 1; i <= n; i ++ )
	{
		for ( int j = 1; j <= n / i; j ++ )
		{
			res[i * j].push_back(i);
		}
	}

	for ( int i = 1; i <= n; i ++ )
	{
		cout << i << "'s divisors:" << endl;
		for ( int j = 0; j < res[i].size(); j ++ )
		{
			cout << res[i][j] << ' ';
		}
		puts("");
	}
	return 0;
}
