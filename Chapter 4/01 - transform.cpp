#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

int main()
{
	std::vector vec{ 1,2,3,4,5,6 };

	std::transform(cbegin(vec), cend(vec), begin(vec),
		[](auto & element) { return element * 2; });

	std::transform(cbegin(vec), cend(vec), begin(vec), std::negate<>());

	std::for_each(begin(vec), end(vec), [](int& i) { i += 1; });

	std::for_each_n(cbegin(vec), size(vec),
		[](const auto & element) { std::cout << element << " "; });


	std::cout << std::endl;
}
