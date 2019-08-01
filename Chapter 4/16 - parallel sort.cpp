#include <iostream>
#include <algorithm>
#include <execution>
#include <vector>

int main()
{
	std::vector largeVector{ 22,11,66,33,22,1,5,9,8,22 };
	using namespace std::execution;
	std::sort(par, begin(largeVector), end(largeVector));


	std::cout << std::endl;
}
