#include <iostream>
#include <functional>

template<typename C, typename... Args>
void process(C callable, Args... args)
{
	// ... Do stuff ...
	std::invoke(callable, std::forward<Args>(args)...);
	// ... Do more stuff ...
}

class Processor {
public:
	void handle(int data)
	{
		std::cout << "Processor::handle()\n";
	}
};

void f(float data)
{
	std::cout << "Global function f()\n";
}

int main()
{
	Processor processor;
	process(&f, 15.85714f);
	process(&Processor::handle, processor, 42);
}
