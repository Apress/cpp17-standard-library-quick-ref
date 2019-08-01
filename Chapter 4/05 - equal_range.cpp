#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector vec{ 1,2,2,3,4 };
	auto result = std::equal_range(cbegin(vec), cend(vec), 2);
	vec.erase(result.first, result.second);    // 1,3,4

	std::cout << std::endl;
}
