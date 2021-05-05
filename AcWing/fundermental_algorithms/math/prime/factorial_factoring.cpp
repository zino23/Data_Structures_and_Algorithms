#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 1e5 + 10;
int primes[N], cnt;
bool st[N];  // mark composite number
unordered_map<int, int> pr;

void get_primes(int n)
{
	for ( int i = 2; i < n; i ++ )
	{
		if ( !st[N] ) primes[cnt ++ ] = i;
		for ( int j = 0; primes[j] <= n / i; j ++ )
		{
			st[primes[j] * i] = true;
			if ( i % primes[j] == 0 ) break;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	get_primes(n);
	for ( int i = 0; i < cnt; i ++ )
	{
		int p = primes[i];
		for ( int j = p; j <= n; j *= p )
		{
			pr[p] += n / j;
		}
	}
	return 0;
}
