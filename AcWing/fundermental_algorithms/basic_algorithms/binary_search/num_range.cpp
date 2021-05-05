#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int a[N];

int bsearch_l( int a[], int l, int r, int k ) {
  // find the smallest i where a[i] >= k ( may be > k in other cases )
  while ( l < r ) {
    int mid = l + r >> 1;
    if ( a[mid] >= k )
      r = mid;
    else
      l = mid + 1;
  }
  if ( a[l] == k )
    return l;
  else
    return -1;
}

int bsearch_r( int a[], int l, int r, int k ) {
  while ( l < r ) {
    int mid = l + r + 1 >> 1;
    if ( a[mid] <= k )
      l = mid;
    else
      r = mid - 1;
  }

  if ( a[l] == k )
    return l;
  else
    return -1;
}

int main() {
  int n, q, k;
  cin >> n >> q;
  for ( int i = 0; i < n; i++ ) scanf( "%d", &a[i] );

  while ( q-- ) {
    cin >> k;
    cout << bsearch_l( a, 0, n - 1, k ) << ' ' << bsearch_r( a, 0, n - 1, k )
         << endl;
  }
  return 0;
}
