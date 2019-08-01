#include <iostream>
#include <optional>

std::optional<double> divide(double n, double d)
{
	if (d != 0.0) return n / d;
	else return std::nullopt;
}

int main()
{
	auto result = divide(12, 3);
	if (result != std::nullopt)
		std::cout << "result is: " << result.value();
}
