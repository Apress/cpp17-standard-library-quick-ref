#include <iostream>
#include <variant>
#include <string>

int main()
{
	std::variant<int, std::string> v1; // Value-constructed variant contains
									   // a value-initialized value of the 
									   // first alternative type (int).
	std::cout << std::holds_alternative<int>(v1) << std::endl;  // 1 (true)
	std::cout << v1.index() << std::endl;                       // 0

	v1 = "In manufacturing, we try to stamp out variance. "
		"With people, variance is everything.";

	std::cout << std::get<1>(v1) << std::endl;                  // In manu...
	std::cout << *std::get_if<std::string>(&v1) << std::endl;   // In manu...
}
