#include <iostream>

using namespace std;

int main()
{
    int n = 10;
    signed int a = -n;
    for (int i = 31; i >=0; i -- ) cout << ((a >> i) & 1);
    return 0;
}