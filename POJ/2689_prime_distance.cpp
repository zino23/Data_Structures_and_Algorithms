#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int N = 1e6 + 10;
int cnt;
int primes[N], st[N];
bool is_prime[N];

void get_primes(int n)
{
	for ( int i = 2; i <= n; i ++ )
	{
		if ( !st[i] ) primes[cnt ++ ] = i;
		for ( int j = 0; primes[j] <= n / i; j ++ )
		{
			st[primes[j] * i] = true;
			if ( i % primes[j] == 0 ) break;
		}
	}
}

int main()
{
	int l, r;
	get_primes(1e6 + 10);
	memset(is_prime, true, sizeof is_prime);
	is_prime[0] = is_prime[1] = false;
	while ( cin >> l >> r )
	{
		if ( r == 1 ) r = 2;
		for ( int i = 0; i < cnt; i ++ )
		{
			int p = primes[i];
			int ll = ( l - 1 ) / p + 1, rr = r / p;  // [l, r]
			ll = max(2, ll);
			for ( int j = ll; j <= rr; j ++ )
			{
				int n = p * j;
				if ( is_prime[n] ) is_prime[n] = false;
			}
		}

		// for ( int i = 0; i <= r; i ++ ) cout << is_prime[i] << ' ';
		// cout << endl;
		vector<int> pr;
		for ( int i = l; i <= r; i ++ )
		{
			if ( is_prime[i] ) pr.push_back(i);
		}

		// cout << "size: " << pr.size() << endl;
		// for ( auto p : pr ) cout << p << endl;
		if ( pr.size() == 1 ) cout << "There are no adjacent primes.\n";
		else
		{
			int res = -1;
			for ( int i = 1; i < pr.size(); i ++ )
			{
				res = max(res, pr[i] - pr[i - 1]);
			}
			cout << res;
		}
		cout << endl;
	}
	return 0;
}
