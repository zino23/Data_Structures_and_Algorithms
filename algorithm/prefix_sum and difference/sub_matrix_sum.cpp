#include <iostream>

using namespace std;

const int N = 1010;
int a[N][N], s[N][N];

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for ( int i = 0; i < n; i ++ )
    {
        for ( int j = 0; j < m; j ++ )
        {
            scanf("%d", &a[i][j]);
            s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] + a[i][j] - s[i][j];
        }
    }

    while ( q -- )
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1] << endl;
    }
    
    return 0;
}