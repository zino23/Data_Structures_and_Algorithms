#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N], n;

void sort()
{
    for ( int i = 1; i < n; i ++ )
    {
        // a[0:i - 1] is already sorted
        for ( int j = i; j >= 1 && a[j] < a[j - 1]; j -- )
        {
            swap(a[j], a[j - 1]); 
        }
    }
}

int main()
{
    cin >> n;
    for ( int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
    sort();
    for ( int i = 0; i < n; i ++ ) printf("%d", a[i]);
    return 0;
}
