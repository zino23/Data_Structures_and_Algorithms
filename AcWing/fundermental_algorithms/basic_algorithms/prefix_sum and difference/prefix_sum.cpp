#include <iostream>

using namespace std;

const int N = 100010;
int s[N], a[N];

int main()
{
    int n, m;
    cin >> n >> m;

    // read data input and initialize prefix sum array
    for (int i = 0; i < n; i ++)
    {
        scanf("%d", &a[i]);
        s[i + 1] = s[i] + a[i];
    }

    int l, r;
    while (m -- )
    {   
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;\
    }
    return 0;
}