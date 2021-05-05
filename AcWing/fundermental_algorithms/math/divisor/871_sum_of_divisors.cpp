#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;
unordered_map<int, int> primes;
LL res = 1;

int main()
{
	int n;
	cin >> n;
	while ( n -- )
	{
		int x;
		cin >> x;
		for ( int i = 2; i <= x / i; i ++ )
		{
			while ( x % i == 0 )
			{
				x /= i;
				primes[i] ++ ;
			}
		}

		if ( x > 1 ) primes[x] ++ ;
	}

	for ( auto pr : primes )
	{
		int sum = 1;
		int p = pr.first, idx = pr.second;
		while ( idx -- )
		{
			sum = ( 1 + sum * p ) % mod;
		}

		res = res * sum % mod;
	}

	cout << res << endl;
	return 0;
}


