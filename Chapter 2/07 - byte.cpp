#include <iostream>
#include <cstddef>

int main()
{
	std::byte b1{ 1 }, b2{ 42 };  // More realistic examples would read bytes
	std::byte b = b1 | b2;        // from a file (Chapter 5), the network, ...
	b <<= 5;
	int v1 = static_cast<int>(b);
	auto v2 = unsigned(b);
	long v3 = std::to_integer<long>(b);
	std::cout << v1 << ' ' << v2 << ' ' << v3 << std::endl; // 96 96 96
}
