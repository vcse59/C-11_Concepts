#include <iostream>
#include <time.h>
#include <chrono>

using namespace std;

class sampleClass{
	public:
	constexpr sampleClass(){
		cout << "Sample Class Constructor" << endl;
	}
	
	~sampleClass(){
		cout << "Sample Class Destructor" << endl;
	}

	void operator()(){
		cout << "() operator " << endl;
	}

	void operator()(int n){
		cout << "() operator " << n << endl;
	}

	constexpr uint8_t arraySize() const
	{
		return 32;
	} 
};


int main(int argc, char *argv[])
{
	auto start = std::chrono::high_resolution_clock::now();
	
	const int c1 = 5;
	
	sampleClass sampleObj1;
	sampleObj1();
	sampleObj1(10);

	// Evaluate the value at compile time
	const uint8_t sizeCompileTime = sampleObj1.arraySize();

	// Evaluate the value at run time
	const uint8_t sizeRunTime = sampleObj1.arraySize();

	const sampleClass sampleObj2;
	const uint8_t sizeSampleObj2 = sampleObj2.arraySize();

	auto elapsed = std::chrono::high_resolution_clock::now() - start;

	long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

	std::cout << "Time Taken in microseconds : " << microseconds << std::endl;
 
	return 0;
}