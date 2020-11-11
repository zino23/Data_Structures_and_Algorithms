#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N], q[N];
int n, k, hh = 0, tt = -1;

int main()
{
    cin >> n >> k;
    for ( int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

    for ( int i = 0; i < n; i ++ )
    {
        // the head element slide out of the window
        if ( hh <= tt && q[hh] < i - k + 1 ) hh ++ ;
        // if the tail element is larger than the to-be-inserted element a[i], pop it
        while ( tt >= hh && a[q[tt]] >= a[i] ) tt -- ;
        // q[] store indexes instead of values
        // insert the new element's (a[i]) index to the tail
        // the tail will be the right position because all elements
        // in front of the tail are larger than a[i]
        q[ ++ tt ] = i;
        if ( i >= k - 1 ) cout << a[q[hh]] << " ";
    }

    hh = 0, tt = -1;
    cout << endl;
    for ( int i = 0; i < n; i ++ )
    {
        if ( hh <= tt && q[hh] < i - k + 1 ) hh ++ ;
        while ( tt >= hh && a[q[tt]] <= a[i] ) tt --;
        q[ ++ tt ] = i;
        if ( i >= k - 1 ) cout << a[q[hh]] << " ";
    }
    return 0;
}
