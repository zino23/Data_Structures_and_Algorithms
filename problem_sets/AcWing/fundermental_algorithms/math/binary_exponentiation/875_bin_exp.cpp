#include <iostream>

using namespace std;

typedef long long LL;
LL bin_exp(int a, int b, int p)
{
	LL res = 1;
	int k = b;
	while ( k )
	{
		if ( k & 1 ) res = res * a % p;
		a = a * (LL) a % p;
		k >>= 1;
	}
	return res;
}
int main()
{
	int n;
	cin >> n;
	while ( n -- )
	{
		int a, b, p;
		cin >> a >> b >> p;
		cout << bin_exp(a, b, p) << endl;
	}
	return 0;
}
