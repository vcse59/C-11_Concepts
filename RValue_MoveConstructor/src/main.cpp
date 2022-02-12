#include <iostream>
#include "SampleClass.h"

void print (uint16_t &i)
{
	std::cout << "Calling l-value reference : " << i << std::endl;
}

void print (uint16_t &&i)
{
	std::cout << "Calling r-value reference : " << i << std::endl;
}

uint16_t sum(uint16_t& a, uint16_t& b)
{
	std::cout << "sum : lValue reference" << std::endl;
	return a + b;
}

uint16_t sum(uint16_t&& a, uint16_t&& b)
{
	std::cout << "sum : rValue reference" << std::endl;
	return a + b;
}

CSampleClass createSampleClass ()
{
	return CSampleClass{111, 222, 333, 444, 555};
}

void printClassName(CSampleClass&& other)
{
	std::cout << "Sample class is an r-value reference" << std::endl;
}

void printClassName(const CSampleClass& other)
{
	std::cout << "Sample class is an l-value reference" << std::endl;
}

int main(int argc, char *argv[])
{
	uint16_t a = 1;
	uint16_t b = 5;
	print(a); // Calling lvalue reference function
	print(6); // Calling r-value reference function
	
	const uint16_t& sumValueLValueRef1 = sum(a, b);
	std::cout << sumValueLValueRef1 << std::endl;

	const uint16_t& sumValueLValueRef2 = sum(56, 24);
	std::cout << sumValueLValueRef2 << std::endl;

	uint16_t&& sumValueRValueRef = sum(56, 44);
	std::cout << sumValueRValueRef << std::endl;

	// Calling constr with intializer list
	std::cout << "==================================================" << std::endl;
	std::cout << "Object creation using initializer_list" << std::endl;
	CSampleClass *obj1 = new CSampleClass{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	obj1->print();

	// Calling copy constructor
	std::cout << "==================================================" << std::endl;
	std::cout << "Constructing object using copy constructor" << std::endl;
	CSampleClass obj2(*obj1);
	obj2.print();

	printClassName(obj2);

	// Calling copy assignment operator
	std::cout << "==================================================" << std::endl;
	std::cout << "Constructing object using copy assignment operator" << std::endl;
	CSampleClass obj3{11, 22, 33, 44, 55};
	obj3.print();
	obj3 = *obj1;
	obj3.print();

	// Calling move constructor
	std::cout << "==================================================" << std::endl;
	std::cout << "Constructing object using move constructor" << std::endl;
	CSampleClass obj4(std::move(obj3));
	obj4.print();

	CSampleClass obj5 = std::move(createSampleClass());
	obj5.print();

	printClassName(CSampleClass{111, 111, 111, 111, 111});

	// Calling move assignment operator
	std::cout << "==================================================" << std::endl;
	std::cout << "Constructing object using move assignment operator" << std::endl;
	CSampleClass obj6{11, 22, 33, 44, 55};
	obj6.print();
	obj6 = std::move(obj5);
	obj6.print();

	// Calling move assignment operator
	obj6 = createSampleClass();
	obj6.print();

	// Calling move assignment operator
	obj6 = CSampleClass{99, 199, 299, 399};
	obj6.print();

	if (obj1 != nullptr) delete obj1;
	obj1 = nullptr;

	return 0;
}