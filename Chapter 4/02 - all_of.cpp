#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector vec{ 1,2,3,4,5,6 };
	bool allEven = std::all_of(cbegin(vec), cend(vec),
		[](auto & element) { return element % 2 == 0; });  // false
	std::cout << allEven << std::endl;
}
