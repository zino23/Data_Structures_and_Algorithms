#include <iostream>
#include <vector>

using namespace std;

int main() {
  int a[4]{0, 1, 2, 3};
  for (auto i : a) { cout << i << endl; }

  vector<bool> b;
  b.assign(3, true);
  for (auto i : b) { cout << i << endl; }

  vector<int> c{1, 2, 4};
  for (auto i : c) { cout << i << ' '; }
  cout << endl;
  return 0;
}
