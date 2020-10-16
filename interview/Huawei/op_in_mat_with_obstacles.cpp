#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 128 + 10;
int res[N][N];

typedef pair<int, int> PII;
vector<PII> ob;

typedef pair<char, int> PCI;
vector<PCI> op;

bool sortbysec(PII &a, PII &b) 
{ 
    return (a.second < b.second); 
} 

// 找到横坐标相同的起点
int find_x_left(vector<PII> v, int x)
{
    int l = 0, r = v.size() - 1;
    while ( l < r )
    {
        int mid = l + r >> 1;
        if ( v[mid].first >= x ) r = mid;
        else l = mid + 1;
    } 
    return l;
}

// 找到横坐标相同的终点
int find_x_right(vector<PII> v, int x)
{
    int l = 0, r = v.size() - 1;
    while ( l < r )
    {
        int mid = l + r + 1 >> 1;
        if ( v[mid].first <= x) l = mid;
        else r = mid - 1;
    }
    return l;
}

// 找到纵坐标相同的起点
int find_y_left(vector<PII> v, int y)
{
    int l = 0, r = v.size() - 1;
    while ( l < r )
    {
        int mid = l + r >> 1;
        if ( v[mid].second >= y ) r = mid;
        else l = mid + 1;
    }
    return l;
}

// 找到纵坐标相同的终点
int find_y_right(vector<PII> v, int y)
{
    int l = 0, r = v.size() - 1;
    while ( l < r )
    {
        int mid = l + r + 1 >> 1;
        if ( v[mid].second <= y) l = mid;
        else r = mid - 1;
    }
    return l;
}

int find_ob_left(vector<PII> v, int y)
{
    int l = 0, r = v.size() - 1;
    while ( l < r )
    {
        int mid = l + r + 1 >> 1;
        if ( v[mid].second < y ) l = mid;
        else r = mid - 1;
    }
    return l;
}

int find_ob_right(vector<PII> v, int y)
{
    int l = 0, r = v.size() - 1;
    while ( l < r )
    {
        int mid = l + r >> 1;
        if ( v[mid].second > y ) r = mid;
        else l = mid + 1;
    }
    return l;
}

int find_ob_up(vector<PII> v, int x)
{
    int l = 0, r = v.size() - 1;
    while ( l < r )
    {
        int mid = l + r + 1 >> 1;
        if ( v[mid].first < x ) l = mid;
        else r = mid - 1;
    }
    return l;
}

int find_ob_down(vector<PII> v, int x)
{
    int l = 0, r = v.size() - 1;
    while ( l < r )
    {
        int mid = l + r >> 1;
        if ( v[mid].first > x ) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main()
{
    int m, b, n;
    cin >> m >> b >> n;
    for ( int i = 0; i < b; i ++ )
    {
        int x, y;
        cin >> x >> y;
        ob.push_back({x, y});
        res[x][y] = -1;
    }

    for ( int i = 0; i < n; i ++ )
    {
        char o;
        int d;
        cin >> o >> d;
        op.push_back({o, d});
    }

    int idx = 0, x = 0, y = 0;
    for ( auto p : op )
    {
        if ( p.first == 'L' )
        {
            // 该行是否有障碍物
            // 二分得到该行/该列离该方向最近的障碍物
            // 先二分得到相同横坐标的起始点，再二分得到相同横坐标的终点，需包含
            sort(ob.begin(), ob.end());
            int l = find_x_left(ob, x), r = find_x_right(ob, x);

            if ( ob[l].first != x )
            {
                y -= p.second;
            }
            else
            {
                vector<PII>::const_iterator st = ob.begin() + l;
                vector<PII>::const_iterator ed = ob.begin() + r + 1;
                vector<PII> v(st, ed);
                int ll = find_ob_left(v, y);
                y = max(v[ll].second + 1, y - p.second);
            }
        
            if ( y < 0 ) 
            {
                cout << "INVALID" << endl;
                y = 0;
            }

            idx += p.second;
            res[x][y] += idx;  
        }
        else if ( p.first == 'R')
        {
            sort(ob.begin(), ob.end());

            // 找到同一行中的障碍物
            int l = find_x_left(ob, x), r = find_x_right(ob, x);

            // 同一行中无障碍物
            if ( ob[l].first != x )
            {
                y += p.second;
            }
            else
            {
                // 找到离该方向最近的障碍物
                vector<PII>::const_iterator st = ob.begin() + l;
                vector<PII>::const_iterator ed = ob.begin() + r + 1;
                vector<PII> v(st, ed);
                int rr = find_ob_right(v, y);
                y = min(v[rr].second - 1, y + p.second);
            }
            
 
            if ( y >= m )
            {
                cout << "INVALID" << endl;
                y = m - 1;
            }
            idx += p.second;
            res[x][y] += idx;  
        }
        else if ( p.first == 'U')
        {   
            sort(ob.begin(), ob.end(), sortbysec);
            int d = find_y_left(ob, y), u = find_y_right(ob, y);

            if ( ob[d].second != y )
            {
                x -= p.second;
            }
            else
            {
                vector<PII>::const_iterator st = ob.begin() + d;
                vector<PII>::const_iterator ed = ob.begin() + u + 1;
                vector<PII> v(st, ed);
                int uu = find_ob_up(v, x);
                x = max(x - p.second, v[uu].first + 1);
            }

            if ( x < 0 )
            {
                cout << "INVALID" << endl;
                x = 0;
            }
            idx += p.second;
            res[x][y] += idx;
        }
        else
        {
            sort(ob.begin(), ob.end(), sortbysec);
            int d = find_y_left(ob, y), u = find_y_right(ob, y);
            
            if ( ob[d].second != y )
            {
                // no obstacles
                x += p.second;
            }
            else
            {
                vector<PII>::const_iterator st = ob.begin() + d;
                vector<PII>::const_iterator ed = ob.begin() + u + 1;
                vector<PII> v(st, ed);
                int dd = find_ob_down(v, x);
                x = min(x + p.second, v[dd].first - 1);
            }

            if ( x >= n )
            {
                cout << "INVALID" << endl;
                x = n - 1;
            }
            idx += p.second;
            res[x][y] += idx;  
        }
    }
    
    for ( int i = 0; i < m; i ++ )
    {
        for ( int j = 0; j < m; j ++ )
        {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}