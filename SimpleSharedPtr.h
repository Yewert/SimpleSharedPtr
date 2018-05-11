#ifndef SIMPLESimpleSharedPtr_SIMPLESimpleSharedPtr_H
#define SIMPLESimpleSharedPtr_SIMPLESimpleSharedPtr_H

#include <iostream>
using namespace std;

template<class T>
class SimpleSharedPtr {
 private:
  T *target;
  int *count{nullptr};

  void increase_counter() {
    if (count != nullptr)
      (*count)++;
    else
      count = new int(1);
  }

  void copy_fields(const SimpleSharedPtr &other) {
    target = other.target;
    count = other.count;
  }

  void dispose() {
    if (count == nullptr)
      return;

    if (--(*count) == 0) {
      cout << "Deleted " << endl;
      delete target;
      delete count;
    }
  }

 public:
  explicit SimpleSharedPtr(T *target) {
    SimpleSharedPtr::target = target;
    increase_counter();
  }

  virtual ~SimpleSharedPtr() {
    dispose();
  }

  SimpleSharedPtr(const SimpleSharedPtr &other) {
    copy_fields(other);
    increase_counter();
  }

  SimpleSharedPtr &operator=(const SimpleSharedPtr other) {
    dispose();
    copy_fields(other);
    increase_counter();
    return *this;
  }

  T &operator*() const {
    return *target;
  }

  T *operator->() const {
    return target;
  }
};


#endif //SIMPLESimpleSharedPtr_SIMPLESimpleSharedPtr_H
