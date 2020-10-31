#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
const int N = 3e5 + 10;

vector<PII> add, query;
vector<int> alls;
int a[N], s[N];

int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l + 1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for ( int i = 0; i < n; i ++ )
    {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }

    for ( int i = 0; i < m; i ++ )
    {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l), alls.push_back(r);
    }

    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    // add elements into a[]
    for ( auto item : add)  a[find(item.first)] += item.second;
    
    // init prefix sum
    for ( int i = 1; i <= alls.size(); i ++ ) s[i] = s[i - 1] + a[i];

    // query and output
    for ( auto q : query)
    {
        cout << s[find(q.second)] - s[find(q.first) - 1] << endl;
    }

    return 0;

}