#include <iostream>
using namespace std;

int x = 10;  // some important variable
inline void dbg() { cerr << "x is " << x << endl; }

int main() {
  dbg();
  cout << "hello" << endl;
  x = 5000;
  dbg();
}
