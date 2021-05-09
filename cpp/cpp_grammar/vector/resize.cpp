#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> a{1, 2, 3};
  a.resize(5, 0);
  for (auto i : a) {
    cout << i << ' ';
  }
  return 0;
}
