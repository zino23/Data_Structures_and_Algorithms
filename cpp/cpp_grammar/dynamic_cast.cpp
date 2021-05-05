#include <iostream>

using namespace std;

class A {
 public:
  virtual void a() { cout << "in class A" << endl; }
  int aa = 1;
};

class B : virtual public A {
 public:
  // void a() { cout << "in class B" << endl; }
  int aa = 2;
};

int main() {
  A *x = new B;
  x->a();
  static_cast<B *>( x )->a();
  dynamic_cast<B *>( x )->a();
  cout << x->aa << endl;
  cout << dynamic_cast<B *>( x )->aa << endl;
  // cannot static_cast via virtual inheritance
  // static_cast<B *>( x )->a();

  // cout << endl;
  // B *y = new B;
  // y->a();
  // // upcast is always safe cos the base class's memory layout is contained by
  // // derived class whether the base class contains virtual function or not,
  // or
  // // if there is virtual inheritance
  // static_cast<A *>( y )->a( 1 );
  // dynamic_cast<A *>( y )->a( 1 );
  // reinterpret_cast<A *>( y )->a( 1 );  // this is dangerous

  return 0;
}
