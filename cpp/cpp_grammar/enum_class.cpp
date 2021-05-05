#include <iostream>

using namespace std;

enum color { red = 10, green, black };

enum class band { Radiohead = 5, Ride, Pink_Floyd };

int main() {
  cout << "green has value: " << green << endl;
  cout << "Ride has value: " << (int)band::Ride << endl;
  return 0;
}
