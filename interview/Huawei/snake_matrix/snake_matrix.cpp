#include <iostream>

using namespace std;

int res[100][100];

int main()
{
    int m, n;
    cin >> m >> n;
    
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    
    for (int i = 0, j = 0, k = 1, direction = 0; k <= m * n; k ++)
    {
        res[i][j] = k;
        int i_next = i + dx[direction];
        int j_next = j + dy[direction];
        if (i_next < 0 || i_next >= m || j_next < 0 || j_next >= n || res[i_next][j_next])
        {
            direction = (direction + 1) % 4;
            i_next = i + dx[direction];
            j_next = j + dy[direction];           
        }
        i = i_next;
        j = j_next;
    }
    
    for (int i =  0; i < m; i ++ )
    {
        for (int j = 0; j < n; j ++ )
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}