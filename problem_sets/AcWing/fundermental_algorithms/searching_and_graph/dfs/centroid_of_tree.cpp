#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;
int h[N], e[N * 2], ne[N * 2], idx;
int ans;
bool st[N];
int n;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int dfs(int node)
{ 
    st[node] = true;
    int sum = 1, max_balance = 0;
    for ( int i = h[node]; i != -1; i = ne[i])
    {
        int t = e[i];
        if ( !st[t] )
        {
            int subnodes = dfs(t);
            max_balance = max(max_balance, subnodes);
            sum += subnodes;
        }
    }
    max_balance = max(max_balance, n - sum);
    ans = min(ans, max_balance);
    
    return sum;
}

int main()
{
    cin >> n;
    int m = n - 1;
    memset(h, -1, sizeof h);
    while ( m -- )
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    ans = n;
    dfs(1);
    cout << ans << endl;
    return 0;
}