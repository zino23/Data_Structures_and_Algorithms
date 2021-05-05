#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;
bool st[N], on_stack[N];
int q[N], hh = 0, tt = -1;
int n, m;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

// the strength of this algorithm
// we add only one line to the normal dfs algorithm using the property that
// the reverse postorder in a DAG is a topological sort
// the downside
// we have to start from the source vertex
bool top_sort(int x)
{
    // st[]: if current vertex is visited
    // on_stack[]: if current vertex is on the path under exploring
    // the vertex is on the path means that the vertex is reachable from the path's source vertex
    // so if the vertex can reach any vertex in the path, there exists a directed cycle
    st[x] = true;
    on_stack[x] = true;
    for ( int i = h[x]; i != -1; i = ne[i] )
    {
        if ( !st[x] ) top_sort(e[i]);
        else if ( on_stack[e[i]] ) return false;
    }
    on_stack[x] = false;
    q[ ++ tt ] =  x;
    return true;
}



int main()
{
    cin >> n >> m;
    while ( m -- )
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
    }

    if ( !top_sort(1) ) cout << "No topological sort";
    else
    {
        for ( int i = tt; i >= hh; i -- ) cout << q[i] << ' ';
    }
    cout << endl;
    return 0;
}
