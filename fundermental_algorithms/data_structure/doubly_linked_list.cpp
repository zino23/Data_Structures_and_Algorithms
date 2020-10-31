#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int l[N], r[N], e[N], idx;

void init()
{
    // head and tail node
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

// insert a node after node k
void insert(int k, int x)
{
    e[idx] = x;
    l[idx] = k, r[idx] = r[k];
    l[r[k]] = idx, r[k] = idx ++ ;
}

// delete node k
// note: in singly linked list, the node after node k is deleted
void del(int k)
{
    l[r[k]] = l[k];
    r[l[k]] = r[k]; 
}

int main()
{
    int m, k, x;
    cin >> m;
    init();
    while ( m -- )
    {
        string op;
        cin >> op;
        if ( op == "L" )
        {
            cin >> x;
            insert(0, x);
        }
        else if ( op == "R")
        {
            cin >> x;
            insert(l[1], x);
        }
        else if ( op == "D" )
        {
            cin >> k;
            del(k + 1);
        }
        else if ( op == "IR" )
        {
            cin >> k >> x;
            insert(k + 1, x);
        }
        else
        {
            cin >> k >> x;
            insert(l[k + 1], x);
        }
    }
    for ( int i = r[0]; i != 1; i = r[i])
    {
        cout << e[i] << ' ';
    }

    cout << endl;
    return 0;
}

