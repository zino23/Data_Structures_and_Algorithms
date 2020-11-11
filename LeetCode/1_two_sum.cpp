#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
vector<PII> nums;
int target;

int main()
{
    int n, x;
    cin >> n >> target;
    for ( int i = 0; i < n; i ++ )
    {
        cin >> x;
        nums.push_back({x, i});
    }

    // two pointers 
    sort(nums.begin(), nums.end());
    for ( int i = 0, j = nums.size() - 1; i < j; i ++ )
    {
        while ( nums[i].first + nums[j].first > target ) j --;
        if ( nums[i].first + nums[j].first == target ) cout << nums[i].second << ' ' << nums[j].second << endl;
    }
    return 0;
}