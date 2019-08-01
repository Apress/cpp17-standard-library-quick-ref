#include <iostream>
#include <type_traits>

int main()
{
	using answer_t = std::integral_constant<int, 42>;
	std::cout << answer_t::value << std::endl; // static 'value' member
	std::cout << answer_t{} << std::endl;      // implicit casting operator
	std::cout << answer_t{}() << std::endl;    // function call operator
}
