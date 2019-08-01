#include <iostream>
#include <numeric>
#include <vector>

int main()
{
	std::vector vec{ 4,2,5,1,3,6 };
	int sum = std::reduce(begin(vec), end(vec));    // 21
	std::cout << sum << std::endl;
}
