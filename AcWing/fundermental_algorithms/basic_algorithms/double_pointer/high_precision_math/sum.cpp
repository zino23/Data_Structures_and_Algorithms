#include <iostream>
#include <cmath>

using namespace std;

const int N = 100010;
int a[N], b[N], c[N];

void high_presicion_sum(int a[], int b[], int c[], string s1, string s2)
{
    int max_len = max(s1.size(), s2.size());
    int increment = 0;
    for (int i = 0; i < max_len; i ++ )
    {
        increment = a[i] + b[i] + increment;
        c[i] = increment % 10;
        increment /= 10;
    }
    if (increment)
    {
        c[max_len] = 1;
        max_len += 1;
    }
    
    for (int i = max_len - 1; i >= 0; i -- ) cout << c[i];
    cout << endl;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i ++ ) a[i] = s1[s1.size() - i - 1] - '0';
    for (int i = 0; i < s2.size(); i ++ ) b[i] = s2[s2.size() - i - 1] - '0';

    high_presicion_sum(a, b, c, s1, s2);

    return 0;
}