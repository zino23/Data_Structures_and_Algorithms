#include <iostream>

using namespace std;

const int N = 100010;

// nodes are connected by their index in array. Index is similar to pointer in dynamic linked list
// head: pointer of head node, point to -1, i.e. null node by default
// e[i]: value of node whose index is i
// ne[i]: pointer of node whose index is i
// idx: index of current usable node
int head, e[N], ne[N], idx;

void init()
{
    head = -1;
    idx = 0;
}

// add node after the head node
void add_to_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx ++ ;
}

// add node to index (k + 1), i.e. after k
void insert(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx ++ ;
}

// remove node (k + 1)
void remove(int k)
{
    ne[k] = ne[ne[k]];
}

int main()
{
    int m, k, x;
    cin >> m;
    char op;
    init();
    while (m -- )
    {
        cin >> op;
        switch (op)
        {
        case 'H':
            cin >> x;
            add_to_head(x);
            break;
        
        case 'D':
            cin >> k;
            if (!k) remove(k - 1);
            else head = ne[head];

        case 'I':
            cin >> k >> x;
            insert(k - 1, x);
        default:
            break;
        }
    }

    for (int i = head; i != -1; i = ne[i])
    {
        cout << e[i] << ' ';
    }
    cout << endl;
    return 0;
}