#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long LL;
unordered_map<int, int> primes;
const int mod = 1e9 + 7;

void num_divisors(int x)
{
	for ( int i = 2; i <= x / i; i ++ )
	{
		while ( x % i == 0 )
		{
			x /= i;
			primes[i] ++;
		}
	}
	
	if ( x > 1 ) primes[x] ++ ;
}

int main()
{
	int n, x = 1;
	cin >> n;
	while ( n -- )
	{
		int a;
		cin >> a;
		num_divisors(a);
	}
	
	LL res = 1;
	for ( auto x : primes ) res = ++ x.second * res % mod;
	res %= mod;
	cout << res << endl;
	return 0;
}
