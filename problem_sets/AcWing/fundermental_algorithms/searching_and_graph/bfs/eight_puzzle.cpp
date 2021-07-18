#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int dfs(string start)
{
    queue<string> q;
    unordered_map<string, int> d;
    q.push(start);
    d[start] = 0;
    
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
    while ( q.size() )
    {
        auto t = q.front();
        q.pop();
        int dist = d[t];
        if ( t == "12345678x" ) return dist;
        int pos = t.find('x');
        int x = pos / 3, y = pos % 3;
        for ( int i = 0; i < 4; i ++ )
        {
            int a = x + dx[i], b = y + dy[i];
            if ( a >= 0 && a < 3 && b >= 0 && b < 3 )
            {
                swap(t[pos], t[a * 3 + b]);
                if ( d.count(t) == 0 )
                {
                    q.push(t);
                    d[t] = dist + 1;
                }
                swap(t[pos], t[a * 3 + b]);
            }
        }
    }
    return -1;
    
}

int main()
{
    char c[2];
    string start;
    for ( int i = 0; i < 9; i ++ )
    {
        cin >> c;
        start += *c;
    }
    cout << dfs(start) << endl;
    return 0;
}