#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int res[N];
bool flag[N];
int n;

void dfs(int x)
{
    if ( x == n )
    {
        for ( int i = 0; i < n; i ++ ) cout << res[i] << ' ';
        cout << endl;
        return;
    }

    for ( int i = 1; i <= n; i ++ )
    {
        if ( !flag[i] )
        {
            res[x] = i;
            flag[i] = true;
            dfs(x + 1);
            flag[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    dfs(0);
    return 0;
}
