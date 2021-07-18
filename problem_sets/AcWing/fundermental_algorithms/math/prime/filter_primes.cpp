#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int primes[N], cnt;
bool st[N];

// 1. naive filtering: for each number from 2 to (x-1)
// filter its multiples
void naive_sieve(int x)
{
	for ( int i = 2; i <= x; i ++ )
	{
		// i must be prime if i has not been marked bc i % x for x in 2:i-1 != 0
		if ( !st[i] ) primes[cnt ++ ] = i;

		for ( int t = 2; t * i <= x; t ++ )
		{
			st[t * i] = true;
		}
	}
}

// 2. Sieve of Eratosthenes: optimization of naive filtering
// bc of prime factorization, every prime can be sieved by one of it prime factor
// only filter when the number is prime
void sieve_eratosthenes(int x)
{
	for ( int i = 2; i <= x; i ++ )
	{
		if ( !st[i] )
		{
			primes[cnt ++ ] = i;
			for ( int j = i + i; j <= x; j += i )
			{
				st[j] = true;
			}
		}
	}
}

// 3. Sieve of Euler: optimization of Sieve of Eratosthenes
// filter each composite number only once with its smallest prime number
void sieve_euler(int x)
{
	for ( int i = 2; i <= x; i ++ )
	{
		if ( !st[i] )  primes[cnt ++ ] = i;
		for ( int j = 0; primes[j] <= x / i; j ++ )
		{
			// number 2 to (i-1) has been filtered
			// so the number needed to be filtered must be larger than i

			// begin with the smallest prime number, filter primes[j] * i
			// Case 1: i %  primes[j] == 0, primes[j] is the smallest prime factor of both i
			// and primes[j] * i
			// Case 2: i % primes[j] != 0, primes[j] is smaller than all of the prime factors of i, so primes[j] is the smallest prime factor of primes[j] * i
			// 'cus if there is a smaller prime factor primes[k] than primes[j], i % primes[k] == 0, the loop will ternimate
			// so, in both cases, primes[j] * i should be filtered
			// and in the case of i % primes[j] == 0, the loop should terminate

			// the idea
			// 1: every composite number x will be filetered by its smallest prime
			// i.e. when primes[j] * i == x
			// 2: euler siege filter composite number primes[j] * i with primes[j]
			// being the smallest prime factor
			st[primes[j] * i] = true;
			if ( i % primes[j] == 0 ) break;  // primes[j] <= i yields true
		}
	}
}

int main()
{
	int n;
	cin >> n;
	sieve_euler(n);
	cout << cnt << endl;
	return 0;
}

