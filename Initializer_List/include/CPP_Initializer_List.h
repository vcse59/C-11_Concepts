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

        std::cout << "Calling initializer list constructor" << std::endl;

        arr = new uint32_t[args.size()];
        uint32_t i = 0;
        for (auto x : args) {
          arr[i++] = x;
        }

        size = args.size();
      }

      CPP_INITIALIZER_LIST_CLASS(uint32_t a, uint32_t b)
        : arr{nullptr}, size{0}
      {
        std::cout << "Calling regular constructor" <<std::endl;

        arr = new uint32_t[2];
        arr[0] = a;
        arr[1] = b;

        size = 2;
      }

      ~CPP_INITIALIZER_LIST_CLASS() {
          if (arr != nullptr) {
              delete arr;
          }
          arr = nullptr;
      }

      void print() const {
          for (uint32_t i = 0; i < size; i++) {
              std::cout << arr[i] << " ";
          }
          std::cout << std::endl;
      }

      //CPP_INITIALIZER_LIST_CLASS(const CPP_INITIALIZER_LIST_CLASS& obj);

      CPP_INITIALIZER_LIST_CLASS& operator=(std::initializer_list<uint32_t>& obj)
      {
        std::cout << "Calling copy constructor with initializer list" << std::endl;

        if(arr != nullptr) {
          delete arr;
        }

        arr = nullptr;
        
        arr = new uint32_t[obj.size()];
        uint32_t i = 0;
        for (auto x : obj) {
          arr[i++] = x;
        }

        size = obj.size();

        return *this;
      }
};

#endif // CPP_INITIALIZER_LIST