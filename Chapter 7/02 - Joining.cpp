#include <iostream>
#include <thread>
#include <string>

double someExpensiveComputation()
{
	return 4.2;
}

int main()
{
	double result;
	std::thread worker([&result] { result = someExpensiveComputation(); });
	// ...
	worker.join();
	std::cout << result << std::endl; // Safe to use result now (see later)
}
