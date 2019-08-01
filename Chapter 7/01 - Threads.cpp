#include <iostream>
#include <thread>
#include <string>

void my_callable(const std::string& str, int i)
{
	/* ... */
}

int main()
{
	int anotherArg = 42;
	std::thread worker1(my_callable, "arg", anotherArg);
	std::thread worker2([=] { my_callable("arg", anotherArg); });

	worker1.join();	// See text.
	worker2.join();	// See text.

	std::cout << std::endl;
}
