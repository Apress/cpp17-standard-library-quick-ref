#include <iostream>
#include <string>
#include <tuple>

void f(const std::string& s, int i)
{
	std::cout << "f() called with: " << s << " and " << i << std::endl;
}

int main()
{
	std::tuple tuple("test", 123);
	std::apply(f, tuple);

	std::cout << std::endl;
}
