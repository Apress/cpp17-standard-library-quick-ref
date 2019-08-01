#include <iostream>
#include <type_traits>

int main()
{
	std::cout << std::boolalpha;            // Print true/false instead of 1/0
	std::cout << std::is_integral<int>::value << '\n';                 // true
	std::cout << std::is_integral_v<char> << '\n';                     // true
	std::cout << std::is_class_v<std::is_class<bool>> << '\n';         // true
	std::cout << std::is_function_v<int(void)> << '\n';                // true
	std::cout << std::is_function_v<decltype(main)> << '\n';           // true
	std::cout << std::is_pointer_v<decltype(&main)> << '\n';           // true
	struct A { void f() {}; };
	void(A:: * p)() = &A::f;
	std::cout << std::is_member_function_pointer<decltype(p)>() << '\n';// true

	std::cout << std::endl;
}
