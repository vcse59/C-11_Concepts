#ifndef CPP_INITIALIZER_LIST
#define CPP_INITIALIZER_LIST

#include <cstdint>
#include <initializer_list>
#include <iostream>

class CPP_INITIALIZER_LIST_CLASS
{
    uint32_t *arr;
    uint32_t size;

    public:
      CPP_INITIALIZER_LIST_CLASS(std::initializer_list<uint32_t> args)
          : arr{nullptr}, size{0} {
        arr = new uint32_t[args.size()];
        uint32_t i = 0;
        for (auto x : args) {
          arr[i++] = x;
        }

        size = args.size();
      }

      ~CPP_INITIALIZER_LIST_CLASS() {
          if (arr != nullptr) {
              delete arr;
          }
          arr = nullptr;
      }

      void print() const {
          for (uint32_t i = 0; i < size; i++) {
              std::cout << arr[i] << std::endl;
          }
      }
};

#endif // CPP_INITIALIZER_LIST