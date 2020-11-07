#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int R = 256;
typedef pair<string, string> PSS;
vector<PSS> s;

void pad()
{
    int max_len = 0;
    for ( int i = 0; i < s.size(); i ++ )
    {
        max_len = max(max_len, (int) s[i].first.size());
    }
    
    for ( int i = 0; i < s.size(); i ++ )
    {
        s[i].second += string(max_len - s[i].second.size(), 'a');
    }
}

void sort(int W)
{
    int l = s.size();
    PSS aux[l];
    for ( int d = W - 1; d >= 0; d -- )
    {
        // frequency
        int cnt[R + 1] = {0};
        for ( int i = 0; i < l; i ++ ) cnt[s[i].second[d] - 'a' + 1] ++ ;

        // starting indexes
        for ( int i = 1; i < R + 1; i ++ ) cnt[i] += cnt[i - 1];
        
        // create aux[]
        for ( int i = 0; i < l; i ++ ) aux[cnt[s[i].second[d] - 'a'] ++ ] = s[i];

        for ( int i = 0; i < l; i ++ ) s[i] = aux[i];
    }
}

int main()
{
    int n, W;
    cin >> n >> W;
    for ( int i = 0; i < n; i ++ )
    {
        string tmp;
        cin >> tmp;
        s.push_back({tmp, tmp});
    }
    
    pad();
    sort(W);
    for ( int i = 0; i < s.size(); i ++ ) cout << s[i].first << endl;

    return 0;
}
