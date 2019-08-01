#include <iostream>
#include <utility>
#include <tuple>
#include "../Common/Person.h"

int main()
{
	// Basic constructor
	std::pair<unsigned int, Person> p1(42u, Person("Douglas", "Adams"));

	// Using C++17 class template argument deduction (CTAD)
	std::pair p2(42u, Person("Douglas", "Adams"));

	// Construction using std::make_pair()
	auto p3 = std::make_pair(42u, Person("Douglas", "Adams"));

	// Piecewise construction
	std::pair<unsigned, Person> p4(std::piecewise_construct,
		std::make_tuple(42u), std::forward_as_tuple("Douglas", "Adams"));

	// Deconstructing a pair with C++17 structured bindings
	auto [number, person] = p1;

	std::cout << std::endl;
}
