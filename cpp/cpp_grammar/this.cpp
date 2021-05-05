#include <iostream>

using namespace std;

class Sales_data {
  public:
    Sales_data(string bn) { bookNo = bn; }
    Sales_data() = default;
    string isbn() { return bookNo; }
    string name() { return bookName; }
    int GetIndex() { return index; }

    string bookName;
    string bookNo;
    long double index;

   private:
    int test = 1;
};

class child : public Sales_data {};

int main() {
  const auto sales = new Sales_data("hello");
  cout << sales->isbn() << endl;

  if ( sales->name().length() == 0 ) {
    cout << "class member of string type without explicit initializer is "
            "initialized to empty string"
         << endl;
  }

  cout << sales->GetIndex() << endl;

  // undefined behavior: may crush, may get random value
  long double a, b;
  cout << a << ' ' << b << endl;

  auto c = child();
  cout << c.test << endl;
  return 0;
}
