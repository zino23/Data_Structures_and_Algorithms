#include <iostream>
#include <string>

using namespace std;

const int N = 1e5 + 10, R = 26;
string a[N], aux[N];
int n;

int char_val(string s, int d)
{
    if ( d == s.size() ) return 0;  // end of string
    else return s[d] - 'a' + 1;  // convert a,b,c,d,...,x,y,z to 0,1,2...,25
}

void insertion_sort(int lo, int hi, int d)
{
    for ( int i = lo + 1; i < hi; i ++ )
    {
        for ( int j = i; j > lo && a[j][d] < a[j - 1][d]; j -- ) swap(a[j], a[j - 1]);
    }
}

void sort(int lo, int hi, int cutoff=0)
{
    int d = 0;
    if ( hi <= lo + cutoff ) 
    {
        insertion_sort(lo, hi, d);
        return;
    }
    
    int cnt[R + 2];
    for ( int i = lo; i < hi; i ++ ) cnt[char_val(a[i], d) + 1] ++ ;

    // convert to starting indexes
    for ( int i =  lo + 1; i < hi; i ++ ) cnt[i] += cnt[i - 1];

    // distribute
    for ( int i = lo; i < hi; i ++ ) aux[cnt[char_val(a[i], d)] ++ ] = a[lo];

    // copy back
    for ( int i = lo; i < hi; i ++ ) a[i] = aux[i];
}

int main()
{
    cin >> n;
    string tmp;
    for ( int i = 0; i < n; i ++ )
    {
        cin >> tmp;
        a[i] = tmp;
    }

    sort(0, n, 10);
    for ( int i = 0; i < n; i ++ ) cout << a[i] << " ";
    cout << endl;

    return 0;
}
