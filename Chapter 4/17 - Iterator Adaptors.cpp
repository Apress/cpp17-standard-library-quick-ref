#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <set>

int main()
{
	std::vector nums{ 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 };
	std::vector<int> evens;
	auto is_even = [](int x) { return x % 2 == 0; };
	std::copy_if(cbegin(nums), cend(nums), back_inserter(evens), is_even);


	std::set<int> odds;
	std::remove_copy_if(cbegin(nums), cend(nums),
		inserter(odds, begin(odds)), is_even);


	std::cout << std::endl;
}
