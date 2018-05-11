#include "SimpleSharedPtr.h"
#include <iostream>
using namespace std;

class testclass{
 public:
  int x;
  testclass(int x, int y) : x(x), y(y) {}
  int y;
};

int main(){
  auto a = SimpleSharedPtr<testclass>(new testclass(10, 20));
  SimpleSharedPtr<testclass> b = SimpleSharedPtr<testclass>(a);
  SimpleSharedPtr<testclass> c = b;
  cout << a->x << endl;
  cout << b->x << endl;
  cout << c->x << endl;
  return 0;
}