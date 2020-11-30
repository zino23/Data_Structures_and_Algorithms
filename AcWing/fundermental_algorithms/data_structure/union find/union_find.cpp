#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int p[N];  // simulate a tree with an array which stores a collection of disjoint-sets

int find(int x)
{
    // if p[x] == x, then p[x] is x's ancestor
    // if not, then let p[x]'s ancestor, i.e. find(p[x]), be x's ancestor
    // do above recursively until find y which p[y] = y
    // then all the node's ancestor from x to y will be set to y
    // so the later operation to find x's ancestor will be O(1)
    if ( p[x] != x ) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    char op[2];
    int a, b;
    cin >> n >> m;
    for ( int i = 1; i <= n; i ++ )
    {
        p[i] = i;  // initialize p disjoint-sets, with node indexes from 1 to n whose ancestor is their index
    }

    while ( m -- )
    {
        scanf("%s%d%d", op, &a, &b);
        if ( *op == 'M' ) p[find(a)] = find(b);  // let b's ancestor be a's ancestor, i.e. merge a into b
        else
        {
            if ( find(a) == find(b) ) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
