#include <iostream>
using namespace std;

class Foo {
 public:
  int x;

  virtual void printStuff() { cout << "Base Foo printStuff called" << endl; }
};

class Bar : public Foo {
 public:
  int y;

  void printStuff() { cout << "derived Bar printStuff called" << endl; }
};

int main() {
  Foo *foo = new Foo;
  foo->printStuff();  /////this call the base function
  foo = new Bar;
  foo->printStuff();
}

