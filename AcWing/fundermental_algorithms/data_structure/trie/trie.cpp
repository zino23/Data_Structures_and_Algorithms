#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int son[N][26], idx, cnt[N];
char str[N];

void insert()
{
    int p = 0;
    for ( int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if ( !son[p][u] ) son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p] ++ ;
}

int query()
{
    int p = 0;
    for ( int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if ( !son[p][u] ) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main()
{
    int n;
    cin >> n;
    char op[2];
    while ( n -- )
    {
        scanf("%s%s", op, str);
        if ( *op == 'I' ) insert();
        else cout << query() << endl;
    }

    return 0;
}
