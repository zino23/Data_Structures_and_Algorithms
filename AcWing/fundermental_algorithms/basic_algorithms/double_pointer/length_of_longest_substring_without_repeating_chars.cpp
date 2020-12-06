#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 1e5 + 10;
int a[N], s[N];

int main()
{
    int n;
    cin >> n;    
    for ( int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

    int res = 0;
    // 当 a 中全为数字，可用数组 s 模拟哈希表，以 a[i] 为 key
    for (int i = 0, j = 0; i < n; i ++ )
    {
        s[a[i]] ++ ;
        while (j < i && s[a[i]] > 1)
        {
            s[a[j]] -- ; 
            j ++ ;
        }
        res = max(res, i - j + 1);
    }

    // 输入不全为数字的一般情况
    // string s;
    // cin >> s;
    // int i = 0, j = 0, res = 0;
    // unordered_map<char, int> m;

    // // 先固定 j，向右移动 i，找到 i 向右最远的位置（不可超过 s.size() ）
    // // 在双指针移动过程中，j 始终小于等于 i
    // // 当 i == j 时，若 i == s.size() - 1，最后一次的 res == 1, 搜索结束
    // //              若 i != s.size() - 1，由于此时 i < s.size() and !m.count(s[i])，i 必然向右移动
    // for ( int i = 0, j = 0; i < s.size(); j ++ )
    // {
    //     // 若 [j, i] 有重复元素，则重复元素必为 s[i]
    //     while ( i < s.size() and !m[s[i]] ) m[s[i ++ ]] ++ ;
    //     res = max(res, i - j);
    //     m[s[j]] -- ;

    // }

    // // 先固定 i，向右移动 j，找到 j 向右最远的位置
    // for ( int i = 0, j = 0; i < s.size(); i ++ )
    // {
    //     m[s[i]] ++ ;
    //     // 若 [j, i] 有重复元素，则重复元素必为 s[i]
    //     while ( j < i and m[s[i]] > 1 ) m[s[j ++ ]] -- ;
    //     res = max(res, i - j + 1);
    // }
    // cout << res << endl;
    
    return 0;
}