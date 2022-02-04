#include <iostream>
#include "SampleClass.h"

CSampleClass::CSampleClass(std::initializer_list<uint32_t> array)
{
    std::cout << "*******************Constructing sample class" << std::endl;
    this->mArray = new uint32_t[array.size()];

    uint32_t index = 0;
    for(auto elem : array)
    {
        this->mArray[index++] = elem;
    }

    this->mSize = array.size();
}

CSampleClass::~CSampleClass()
{
    std::cout << "*******************Destroying sample class" << std::endl;
    if(this->mArray) delete[] this->mArray;
    this->mArray = nullptr;
    this->mSize = 0;
}

CSampleClass::CSampleClass(const CSampleClass& other)
{
    std::cout << "*******************Copy constructor" << std::endl;

    this->mArray = new uint32_t[other.mSize];

    for( uint32_t index = 0; index < other.mSize; index++)
    {
        this->mArray[index] = other.mArray[index];
    }

    this->mSize = other.mSize;
}

CSampleClass& CSampleClass::operator=(const CSampleClass& other)
{
    std::cout << "*******************Copy assignment operator" << std::endl;
    if (this->mArray) delete[] this->mArray;
    this->mArray = nullptr;
    this->mSize = 0;

    this->mArray = new uint32_t[other.mSize];

    for( uint32_t index = 0; index < other.mSize; index++)
    {
        this->mArray[index] = other.mArray[index];
    }

    this->mSize = other.mSize;
    return *this;
}

CSampleClass::CSampleClass(CSampleClass&& other)
{
    std::cout << "*******************Move constructor" << std::endl;
    this->mArray = other.mArray;
    this->mSize = other.mSize;
    other.mArray = nullptr;
    other.mSize = 0;
}

CSampleClass& CSampleClass::operator=(CSampleClass&& other)
{
    std::cout << "*******************Move assignment operator" << std::endl;
    if (this == &other) return *this;

    delete []mArray;

    this->mArray = other.mArray;
    this->mSize = other.mSize;

    other.mArray = nullptr;
    other.mSize = 0;

    return *this;
}

void CSampleClass::print() const
{
    std::cout << "Array content : ";
    for( uint32_t index = 0; index < this->mSize; index++)
    {
        std::cout << this->mArray[index] << " ";
    }
    std::cout << std::endl;
}