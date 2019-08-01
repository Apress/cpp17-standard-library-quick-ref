#include <iostream>
#include <variant>
#include <string>

int main()
{
	std::variant<int, std::string> v(std::in_place_type<std::string>, "Hello");
}
