#ifndef CPP_INITIALIZER_LIST_TEMPLATE
#define CPP_INITIALIZER_LIST_TEMPLATE

#include <cstdint>
#include <initializer_list>
#include <iostream>

template <class T>
class CPP_INITIALIZER_LIST_CLASS_TEMPLATE
{
    T *arr;
    uint32_t size;

    public:
      
      CPP_INITIALIZER_LIST_CLASS_TEMPLATE(std::initializer_list<T> args)
          : arr{nullptr}, size{0} {

        std::cout << "Calling initializer list template constructor" << std::endl;

        arr = new T[args.size()];
        uint32_t i = 0;
        for (auto x : args) {
          arr[i++] = x;
        }

        size = args.size();
      }

      CPP_INITIALIZER_LIST_CLASS_TEMPLATE(T a, T b)
      {
        std::cout << "Calling regular template constructor" << std::endl;

        arr = new T[2];
        arr[0] = a;
        arr[1] = b;

        size = 2;
      }

      ~CPP_INITIALIZER_LIST_CLASS_TEMPLATE() {
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
};

#endif // CPP_INITIALIZER_LIST_TEMPLATE