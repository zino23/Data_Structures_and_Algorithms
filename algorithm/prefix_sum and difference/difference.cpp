#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N], b[N];

void insert(int b[], int l, int r, int c)
{
    b[l] += c;
    b[r + 1] -= c;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for ( int i = 1; i <= n; i ++ )
    {
        scanf("%d", &a[i]);
        insert(b, i, i, a[i]);
    }

    while ( m -- )
    {
        int l, r, c;
        cin >> l >> r >> c;
        insert(b, l, r, c);
    }

    for (int i = 1; i <= n; i ++ )
    {
        b[i] += b[i - 1];
        cout << b[i] << ' ';
    }
    
    return 0;
}