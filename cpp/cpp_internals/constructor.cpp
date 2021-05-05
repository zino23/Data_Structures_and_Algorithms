#include <iostream>

using namespace std;

class X { public: int i; };
class A : public virtual X { public: int j; };
class B : public virtual X { public: double d; };
class C : public A, public B { public: int k; };

void foo( A* pa )
{
	pa->i = 1024;
	// cout << pa->i << endl;
}

int main()
{
	foo( new A );
	foo( new C );
	return 0;
}
