#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;
vector<PII> segs;

void merge(vector<PII> &segs)
{
    vector<PII> res;

    // init begging interval
    int st = -2e9, ed =  -2e9;
    for ( auto seg : segs )
    {
        if ( ed < seg.first )
        {
            if ( ed != -2e9 ) res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }
        else ed = max(ed, seg.second);
    }
    
    // add last interval to res except there is no element in segs
    if ( ed != -2e9 ) res.push_back({st, ed});
    segs = res;
}

int main()
{
    int n;
    cin >> n;
    int l, r;
    for ( int i = 0; i < n; i ++ )
    {
        scanf("%d%d", &l, &r);
        segs.push_back({l, r});
    }

    sort(segs.begin(), segs.end());
    merge(segs);
    cout << segs.size() << endl;
    return 0;
}