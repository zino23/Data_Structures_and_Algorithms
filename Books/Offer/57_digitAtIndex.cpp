class Solution {
 public:
  int power(int a, int b) {
    if (b == 0) return 1;
    int res = 1;
    while (b--) { res *= a; }
    return res;
  }

  int digitAtIndex(int n) {
    if (n <= 0) return 0;
    long long num = 0, last_num = 0, cnt = 0;
    // num = 1 + 9 * 1 + 90 * 2 + ...
    // num = num + 9 * 10 ^ (cnt - 1) * cnt
    double base = 0.1;
    while (num < n) {
      cnt++;
      base *= 10;
      last_num = num;
      num += 9 * base * cnt;
    }
    int a = n - last_num;
    int b = a / cnt;
    int r = a % cnt;

    int res = base + b;
    if (r == 0) {
      return (res - 1) % 10;
    } else {
      int base = 1;
      while (r < cnt) {
        base *= 10;
        r++;
      }
      return res / base % 10;
    }
  }
};

