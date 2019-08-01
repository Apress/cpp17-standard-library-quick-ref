#include <iostream>
#include <optional>
#include <string>

int main()
{
	auto opt = std::optional<std::string>(std::in_place, "Hello");
}
