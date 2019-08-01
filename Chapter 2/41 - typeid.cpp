#include <iostream>
#include <typeinfo>

int main()
{
	const std::string s = "Hello";
	std::cout << typeid(s).name() << '\n';
	std::cout << (typeid(typeid(s).name()) == typeid(s.data())); // 1 (true)

	std::cout << std::endl;
}
