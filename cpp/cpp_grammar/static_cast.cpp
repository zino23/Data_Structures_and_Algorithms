#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class A {
 public:
  int aa = 23;
  void a() { cout << "In class A. aa is: " << aa << endl; }
};

class B : public A {
 public:
  void b() { cout << "In class B" << endl; }
};

int main() {
  // raw pointer
  A *ptr = new B();
  auto p = static_cast<B *>( ptr );
  ptr->a();  // a still be be used
  p->b();

  delete ptr;
  p->a();    // undefined behaviour, may produce the same results cos the memory
             // freed has not been reused
  ptr->a();  // undefined behaviour

  vector<int> v = { 99 };
  for ( int i = 100; i >= 0; i-- ) {
    v.push_back( i );
  }
  ptr->a();  // now the value of aa may change
  p->a();

  // Smart poiters
  // unique_ptr<A> ptr( new B() );
  // auto p = static_cast<B *>( ptr.get() );
  // ptr->a();
  // p->b();
  // delete p;
  // ptr->a();
  // p->b();
  return 0;
}
