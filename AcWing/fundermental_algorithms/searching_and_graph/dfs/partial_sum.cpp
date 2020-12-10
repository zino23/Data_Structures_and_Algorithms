#include <iostream>

using namespace std;

const int N = 30;
int a[N], st[N];
int n, k;

// the state is composed of current idx and sum
bool bfs(int idx, int sum)
{
    if ( idx == n ) return sum == k;
    if ( bfs(idx + 1, sum + a[idx]) or bfs(idx + 1, sum) ) return true;
    return false; 
}

int main()
{
    cin >> n >> k;
    for ( int i = 0; i < n; i ++ ) cin >> a[i];
    cout << bfs(0, 0) << endl;
    return 0;
}
