#include <iostream>
#include <array>

int main()
{
	int array[]{ 1, 2, 3 };
	std::cout << std::size(array) << std::endl;   // 3

	// old-school alternative
	std::cout << sizeof(array) / sizeof(array[0]) << std::endl;
}
