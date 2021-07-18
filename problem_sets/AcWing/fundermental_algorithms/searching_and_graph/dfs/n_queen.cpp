#include <iostream>

using namespace std;

const int N = 20;
char res[N][N];
bool col[N], dg[N], udg[N];
int n;

void dfs(int u)
{
    if ( u == n )
    {
        for ( int i = 0; i < n; i ++ ) printf("%s\n", res[i]);
        puts("");
        return;
    }

    for ( int i = 0; i < n; i ++ )
    {
        if ( !col[i] && !dg[n + i - u] && !udg[i + u])
        {
            res[u][i] = 'Q';
            col[i] = dg[n + i - u] = udg[i + u] = true;  // position (u, i)'s column, diagnal and anti-diagnal is taken
            dfs(u + 1);  // recursively find the next available position
            col[i] = dg[n + i - u] = udg[i + u] = false;  // reset the position as available
            res[u][i] = '.';
        }
    }
}

int main()
{
    cin >> n;
    for ( int i = 0; i < n; i ++ )
    {
        for ( int j = 0; j < n; j ++ ) res[i][j] = '.';
    }

    dfs(0);
    return 0;
}