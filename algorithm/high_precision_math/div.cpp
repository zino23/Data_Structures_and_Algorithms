#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> a, res;
int b, r;  // divisor and quotient

vector<int> div(vector<int> a, int b, int &r)
{
    r = 0;
    for (int i = a.size() - 1; i >= 0; i -- )
    {
        r = r * 10 + a[i];
        res.push_back(r / b);
        r %= b;
    }

    reverse(res.begin(), res.end());
    // remove 0s at the beginning
    while (res.size() > 1 and res.back() == 0) res.pop_back();
    return res;
}

int main()
{
    string s;
    cin >> s >> b;
    for (int i = s.size() - 1; i >= 0; i -- ) a.push_back(s[i] - '0');
    res = div(a, b, r);
    for (int i = res.size() - 1; i >= 0; i -- ) cout << res[i];
    cout << endl << r << endl;
}