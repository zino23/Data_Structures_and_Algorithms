#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void get_divisor(int x)
{
	vector<int> res;	
	for ( int i = 1; i <= x / i; i ++ )
	{
		if ( x % i != 0 ) continue;
		if ( i == x / i ) res.push_back(i);
		else
		{
			res.push_back(i), res.push_back(x / i);
		}
	}
	sort(res.begin(), res.end());
	for ( int i = 0; i < res.size(); i ++ ) cout << res[i] << ' ';
	puts("");
}

int main()
{
	int n;
	cin >> n;
	while ( n -- )
	{
		int x;
		cin >> x;
		get_divisor(x);
	}
	return 0;
}
