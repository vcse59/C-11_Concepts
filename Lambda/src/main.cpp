#include <iostream>
#include "sample.h"

int main(int argc, char *argv[])
{
	// Default capture clause 
	auto addition = [] (uint32_t a, uint32_t b) -> uint32_t 
	{
		return a+b;
	};
	std::cout << "Default capture clause : " << addition(5, 6) << std::endl;

	// Capture clause by reference
	uint32_t b = 10;
	auto sumRef = [&](uint32_t a) -> uint32_t
	{
		b++;
		return a + b;
	};
	std::cout << "Capture clause by reference : " << sumRef(5) << " -> b(" << b << ")" << std::endl;

	// Capture clause by value with mutable keyword
	auto sumMutableByBalue = [=]  (uint32_t a) mutable -> uint32_t
	{
		b = 20;
		return a + b;
	};
	std::cout << "Capture clause by value with mutable : " << sumMutableByBalue(5) << " -> b(" << b << ")" << std::endl;

	// Capture clause by reference for class object and this operator in lambda
	Sample *obj = new Sample(5);
	auto sumRefObj = [&](uint32_t a) -> uint32_t
	{
		obj->doubleValue();
		return a + obj->getValue();
	};
	std::cout << "Capture clause by reference for class object and this operator in lambda : " << sumRefObj(5) << " -> b(" << b << ")" << std::endl;
	std::cout << "Sample member variable value with mutable : " << obj->getValue() << std::endl;
	// Capture clause by value with mutable keyword
	// ------error: assignment of read-only variable ‘b’
	// auto sumByBalue = [=]  (uint32_t a)  -> uint32_t   
	// {
	// 	b = 20;
	// 	return a + b;
	// };
	std::cout << "NOTE :  Capture clause by value without mutable throws \"error: assignment of read-only variable \'b\'"  << std::endl;

	return 0;
}