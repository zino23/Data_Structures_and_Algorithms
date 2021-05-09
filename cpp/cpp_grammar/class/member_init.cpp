#include <iostream>
using namespace std;

class A {
 public:
  int a;
  A(int _a) : a(_a){};
};

class B {
 public:
  int a = 2;
  B(int _a) : a(_a){};
  B() {}
};

int main() {
  auto x = A(1);
  auto y = B(1);
  auto z = B();
  cout << x.a << endl;
  cout << y.a << endl;
  cout << z.a << endl;
  return 0;
}
