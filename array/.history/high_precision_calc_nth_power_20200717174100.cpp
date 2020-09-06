#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int n, max_len;
    cin >> n;
    max_len = (int) n * log2(10) + 10;
    int *a;  // dynamically allocates memory
    a = new int [max_len]{1};  // 第一位初始为 1，其余初始为 0
    int max = 0;  // 初始最高位是个位，根据进位判断是否改变最高位
    for (int i = 0; i < n; i ++)  // nth power
    {
        int increment = 0;  // 初始进位为 0 
        for (int j = 0; j <= max; j ++)
        {
            increment = a[j] * 2 / 10;  // 先算进位，再算本位，否则本位会改变
            a[j] = a[j] * 2 % 10;
        }

        if (increment) a[max ++] += 1;  // 若进位，则高一位加一，同时最高位 max 加一
    }

    // 倒序输出
    for (int i = max; i >= 0; i --)
    {
        cout << a[i];
    }

    cout << endl;
    delete[] a;
    return 0;
}