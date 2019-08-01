#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

int main()
{
	std::vector<int> numbers{ 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 };
	std::vector<int> evens(numbers.size());
	auto end = std::copy_if(cbegin(numbers), cend(numbers), begin(evens),
		[](int x) { return x % 2 == 0; });
	evens.erase(end, evens.end());    // 2 8 34 144

	std::cout << std::endl;
}
