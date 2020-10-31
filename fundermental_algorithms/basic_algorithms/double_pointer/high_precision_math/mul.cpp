#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int N = 100010;
vector<int> a, c;

vector<int> mul(vector<int> a, int b)
{
    /*
        b is a small number compared to a
    */

    int increment = 0;
    
    for (int i = 0; i < a.size() || increment; i ++ )
    {
        if (i < a.size()) increment += a[i] * b;
        c.push_back(increment % 10);
        increment /= 10;
    }
    return c;
}
int main()
{
    string s1;
    int b;
    cin >> s1 >> b;
    for (int i = 0; i < s1.size(); i ++ ) a.push_back(s1[s1.size() - i - 1] - '0');

    auto c = mul(a, b);
    for (int i = c.size() - 1; i >= 0; i -- ) cout << c[i];
    cout << endl;
    
    return 0;
}