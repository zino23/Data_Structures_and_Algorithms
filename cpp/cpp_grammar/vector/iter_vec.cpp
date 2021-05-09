#include <iostream>
#include <vector>

using namespace std;
vector<int> a;

int main() {
  for ( int i = 0; i < 3; i++ ) {
    a.push_back(i);
  }

  for ( auto i = a.begin(); i != a.end(); i++ ) {
    cout << *i << endl;
  }
  return 0;
}

