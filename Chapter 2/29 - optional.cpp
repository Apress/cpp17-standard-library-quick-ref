#include <iostream>
#include <optional>

std::optional<double> divide(double n, double d)
{
	if (d != 0.0) return n / d;
	else return {};
}

int main()
{
	auto result = divide(12, 3);
	if (result.has_value())
		std::cout << "result is: " << result.value();
}
