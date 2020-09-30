#include <iostream>
#include <cmath>

using namespace std;

double n, mid;

int main()
{
    cin >> n;
    // note: the left and right boundary should be set as 0 and n, cause if n == 0.1, then pow(n, 1./3.) > 0.1
    double l = -10000, r = 10000;  
    while (r - l > 1e-8)  // pow(x, 3) increase monotonically
    {
        mid = (l + r) / 2.;
        if (pow(mid, 3) > n) r = mid;
        else l = mid;
    }
    printf("%.6lf\n", mid);
    return 0;
}