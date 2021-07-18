#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N];

int lowbit(int a)
{
    return a & -a;
}

int main()
{
    int n;
    cin >> n;
    for ( int i = 0; i < n; i ++ )
    {
        scanf("%d", &a[i]);
        int cnt = 0;
        while (a[i])
        {
            a[i] -= lowbit(a[i]);
            cnt ++ ;
        }
        cout << cnt << ' ';
    }
    return 0;
}