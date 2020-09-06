#include <iostream>
#include <vector>

using namespace std;

const int N = 100010;
vector<int> a, b, c;

bool cmp(vector<int>a, vector<int> b)
{
    if (a.size() != b.size()) return a.size() > b.size();
    else
    {
        for (int i = a.size() - 1; i >= 0; i -- )
        {
            if (a[i] != b[i]) return a[i] > b[i];
        }
    }
    return true;
}

vector<int> high_presicion_subtraction(vector<int> a, vector<int> b)
{
    int rent = 0;
    for (int i = 0; i < a.size(); i ++ )
    {
        rent = a[i] - rent;
        if (i < b.size()) rent -= b[i];
        c.push_back((rent + 10) % 10);
        if (rent >= 0) rent = 0;
        else rent = 1;
    }
    return c;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i ++ ) a.push_back(s1[s1.size() - i - 1] - '0');
    for (int i = 0; i < s2.size(); i ++ ) b.push_back(s2[s2.size() - i - 1] - '0');

    if (cmp(a, b)) c = high_presicion_subtraction(a, b);
    else c = high_presicion_subtraction(b, a);

    while (c.back() == 0 && c.size() > 1) c.pop_back();
    if (!cmp(a, b)) cout << "-";
    for (int i = c.size() - 1; i >= 0; i -- ) cout << c[i];
    cout << endl;
    return 0;
}
