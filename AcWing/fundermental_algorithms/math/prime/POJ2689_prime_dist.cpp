#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

const int N = static_cast<int>(static_cast<float>(1e6));
int primes[N];
bool flag[N];
int cnt;

void linear_sieve(int n)
{
	for ( int i = 2; i <= n; i ++ )
	{
		if ( !flag[i] ) primes[cnt ++] = i;
		for ( int j = 0; primes[j] <= n / i; j ++ )
		{
			flag[primes[j] * i] = true;
			if ( i % primes[j] == 0 ) break;
		}
	}
}

int pr_dist(int l, int r)
{
	if ( r == 1 ) return 0;
	bool st[r];
	memset(st, false, sizeof st);
	bool is_prime[N];
	memset(is_prime, true, sizeof is_prime);
	is_prime[0] = is_prime[1] = false;

	for ( int i = 0; i < cnt; i ++ )
	{
		int pr = primes[i];
		int ll = ( l % primes[i] == 0 ) ? l / primes[i] : l / primes[i] + 1;

		// or better
		// int ll = ( l - 1 ) / pr + 1;
		ll = max(2, ll);
		int rr = r / pr;
		for ( int j = ll; j <= rr; j ++ )
		{
			int x = pr * j;
			if ( !st[x] ) st[x] = true;
			if ( is_prime[x] ) is_prime[x] = false;
		}
	}

	vector<int> p;
	for ( int i = l; i <= r; i ++ )
	{
		if ( !st[i] ) p.push_back(i);
		// if ( is_prime[i] ) p.push_back(i);
	}

	int res = -1;
	// for ( int i = 0; i < p.size(); i ++ ) cout << p[i] << ' ';
	// cout << endl;
	for ( int i = 1; i < p.size(); i ++ ) res = max(res, p[i] - p[i - 1]);
	return res;
}

int main()
{
	int l, r;
	linear_sieve(1e6);
	while ( cin >> l >> r )
	{
		int res = pr_dist(l, r);
		if ( res == 0 ) cout << "There are no adjacent primes.\n";
		else cout << res;
		cout << endl;
	}
	return 0;
}
