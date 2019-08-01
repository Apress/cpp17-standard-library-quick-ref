#include <iostream>
#include <any>

int main()
{
	std::any a;
	std::cout << a.has_value() << std::endl;                 // 0
	a = 42;
	std::cout << a.type().name() << std::endl;               // int
	a = "Any sufficiently advanced technology is indistinguishable from magic";
	std::cout << a.type().name() << std::endl;               // const char*  
	std::cout << std::any_cast<const char*>(a) << std::endl; // Any suffi...
	a.reset();
	std::cout << a.type().name() << std::endl;               // void
}
