#include <iostream>
#include <cstdio>

using namespace std;

void factoring(int x)
{
		for ( int i = 2; i <= x / i; i ++ )
		{
				int cnt = 0;
				while ( x % i == 0 )
				{
						x /= i;
						cnt ++ ;
				}
				printf("%d %d\n", i, cnt);
		}

		if ( x > 1 ) printf("%d %d\n", x, 1);
}

int main()
{
		int n;
		cin >> n;
		while ( n -- )
		{
				int x;
				cin >> x;
				factoring(x);
		}
		return 0;
}
