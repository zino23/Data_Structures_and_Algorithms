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

            increment += a[j] * 2;  // 下一位的进位加上当前位 * 2
            a[j] = increment % 10;  // 本位
            increment /= 10;  // 进位
        }

        if (increment) a[++ max] += 1;  // 若当前最高位进位，则最高位 max 加一，同时给 (max+1) 位加一
    }

    // 倒序输出
    for (int i = max; i >= 0; i --)
    {
        cout << a[i];
    }

    cout << endl;
    delete[] a;  // release memory 
    return 0;
}