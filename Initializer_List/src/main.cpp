#include <cstdint>
#include <initializer_list>
#include <iostream>
#include  "CPP_Initializer_List.h"
#include  "CPP_Initializer_List_Template.h"

int main(int argc, char *argv[])
{
  std::initializer_list<uint32_t> list = {1, 2, 3, 4};

  // Iterating over std::initializer_list using iterators
  std::cout << "Iterating initializer_list using member function iterators" << std::endl;
  for (const uint32_t* it = list.begin(); it != list.end();it++) {
    std::cout << *it << " ";
	}
  std::cout << std::endl;

  std::cout << "Iterating initializer_list using non-member function iterators" << std::endl;
  for (const uint32_t* it = begin(list); it != end(list); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  
  // Intializing constructor with std::initializer_list
  CPP_INITIALIZER_LIST_CLASS *obj = new CPP_INITIALIZER_LIST_CLASS {10, 20, 30 ,40};
  
  if (obj == nullptr) {
    std::cerr << "Cannot initialize object" << std::endl;
    return -1;
  }

  obj->print();

  if (obj != nullptr) {
    delete obj;
  }
  obj = nullptr;

  // Initializing constructor with regular constructor
  obj = new CPP_INITIALIZER_LIST_CLASS(80, 100);
  
  if (obj == nullptr) {
    std::cerr << "Cannot initialize object" << std::endl;
    return -1;
  }

  obj->print();
  
  if (obj != nullptr) {
    delete obj;
  }
  obj = nullptr;

  // Initializing template constructor with regular constructor
  CPP_INITIALIZER_LIST_CLASS_TEMPLATE<uint32_t> *tempObj = new CPP_INITIALIZER_LIST_CLASS_TEMPLATE<uint32_t> {100, 200, 300, 400};
  
  if (tempObj == nullptr) {
    std::cerr << "Cannot initialize object" << std::endl;
    return -1;
  }
  tempObj->print();

  if (tempObj != nullptr) {
    delete tempObj;
  }
  tempObj = nullptr;

  // Initializing template constructor with regular constructor
  tempObj = new CPP_INITIALIZER_LIST_CLASS_TEMPLATE<uint32_t> (800, 1000);
  
  if (tempObj == nullptr) {
    std::cerr << "Cannot initialize object" << std::endl;
    return -1;
  }
  tempObj->print();

  if (tempObj != nullptr) {
    delete tempObj;
  }
  tempObj = nullptr;

  // Initializer_list in initalizing fixed size arrays
  std::cout << "Initialization of fixed size arrays" << std::endl;
  uint32_t arr[] {11, 21, 31, 41, 51};
  for (auto elem : arr) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  // Initializer_list in initializing dynamic allocated arrays
  std::cout << "Initialization of dynamic allocated array" << std::endl;
  uint32_t *arrDynamic {new uint32_t[7] {11, 22, 33, 44, 55, 66, 77}};
  for (auto elem{0}; elem < 7; elem++) {
    std::cout << arrDynamic[elem] << " ";
  }
  delete arrDynamic;
  std::cout << std::endl;

  // Initializer_list in initializing dynamic allocated arrays
  std::cout << "Initialization of dynamic allocated array without braces for new" << std::endl;
  arrDynamic = new uint32_t[7] {11, 22, 33, 44, 55, 66, 77};
  for (auto elem{0}; elem < 7; elem++) {
    std::cout << arrDynamic[elem] << " ";
  }
  delete arrDynamic;
  std::cout << std::endl;

  // Calling copy constructor and intialize array with std::initializer_list values
  CPP_INITIALIZER_LIST_CLASS *copyConstructorObj = new CPP_INITIALIZER_LIST_CLASS(200, 300);
  std::initializer_list<uint32_t> copyList = {99, 199, 299, 399, 499, 599};
  *copyConstructorObj = copyList;
  copyConstructorObj->print();
  if(copyConstructorObj != nullptr)
  {
    delete copyConstructorObj;
  }
  copyConstructorObj = nullptr;
  
	return 0;
}