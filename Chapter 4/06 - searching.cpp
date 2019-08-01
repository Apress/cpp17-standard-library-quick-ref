#include <iostream>
#include <algorithm>
#include <string>
#include <functional>

int main()
{
	std::string needle = "hat";
	std::string stack = "Burn the haystack. What's left is the needle.";
	const std::boyer_moore_searcher searcher(begin(needle), end(needle));
	const auto found = std::search(begin(stack), end(stack), searcher);
	std::cout << "Found at position " << std::distance(begin(stack), found);

	std::cout << std::endl;
}
