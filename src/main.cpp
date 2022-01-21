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

	return 0;
}