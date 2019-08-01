#include <iostream>
#include <ratio>
#include <typeinfo>

int main()
{
	using a_third = std::ratio<1, 3>;
	using a_half = std::ratio<1, 2>;
	using two_quart = std::ratio<2, 4>;
	using sum = std::ratio_add<a_third, a_half>;

	std::cout << two_quart::num << '/' << two_quart::den << '\n';     // 1/2
	std::cout << sum::num << '/' << sum::den << '\n';                 // 5/6
	std::cout << std::boolalpha;        /* print true/false instead of 1/0 */
	std::cout << (typeid(two_quart) == typeid(a_half)) << '\n';       // false
	std::cout << (typeid(two_quart::type) == typeid(a_half)) << '\n'; // true
	std::cout << std::ratio_equal<two_quart, a_half>::value << '\n';  // true  

	std::cout << std::endl;
}
