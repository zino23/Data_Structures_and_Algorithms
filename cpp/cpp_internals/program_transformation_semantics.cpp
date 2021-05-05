// given
class X {};

X bar()
{
	X xx;
	// process xx ...
	return xx;
}

// the steps for bar()'s return value constructed
// from local object xx
// 1. add an additional arguement of type reference to the class object to bar()
// this argument will hold the copy constructed "return value"
void bar( X& __return )
{
	X xx;
	// process xx ...
	__return.X::X( xx );
	return;
}

// 2. transform each invocation of foo() to reflect its new definition
// e.g.
X xx = bar();
// will be transformed to
X xx;  // no default constructor applied
bar(xx);
