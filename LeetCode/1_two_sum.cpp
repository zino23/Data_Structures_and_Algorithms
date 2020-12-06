#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

typedef pair<int, int> PII;
int target;

int main()
{
    int n, x;
    cin >> n >> target;

    // vector<PII> nums;
    // for ( int i = 0; i < n; i ++ )
    // {
    //     cin >> x;
    //     nums.push_back({x, i});
    // }

    // two pointers 
    // sort(nums.begin(), nums.end());
    // for ( int i = 0, j = nums.size() - 1; i < j; i ++ )
    // {
    //     while ( nums[i].first + nums[j].first > target ) j --;
    //     if ( nums[i].first + nums[j].first == target ) cout << nums[i].second << ' ' << nums[j].second << endl;
    // }

    // hashmap
    vector<int> nums;
    for ( int i = 0; i < n; i ++ )
    {
        cin >> x;
        nums.push_back(x);
    }
    unordered_map<int, int> d;
    vector<int> ans(2, -1);
    int i = 0;
    for ( auto u : nums )
    {
        if ( d.count(target - u) )
        {
            ans[0] = d[target - u];
            ans[1] = i;
            break;
        }
        d[u] = i ++ ;
    }

    for ( int i = 0; i < 2; i ++ ) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}