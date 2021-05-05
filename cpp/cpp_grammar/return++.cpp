#include <iostream>

using namespace std;

int a = 0;
int test() {
  return a++;
}
int main() {
  cout << test() << endl;
  return 0;
}
