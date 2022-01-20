#include "CPP_Initializer_List.h"
#include <cstdint>
#include <initializer_list>
#include <iostream>

int main(int argc, char *argv[])
{
  std::initializer_list<uint32_t> list = {1, 2, 3, 4};

  for (auto val : list) {
    std::cout << val << std::endl;
	}

    CPP_INITIALIZER_LIST_CLASS *obj = new CPP_INITIALIZER_LIST_CLASS {10, 20, 30 ,40};
    obj->print();

	return 0;
}