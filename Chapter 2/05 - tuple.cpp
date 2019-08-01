#include <iostream>
#include <string>
#include <tuple>

int main()
{
	std::tuple t(1, 2, 0.3, std::string("4"));   // Using C++17 CTAD
	// auto t = std::make_tuple(1, 2, 0.3, std::string("4")); // Using make_tuple()
	std::cout << std::get<0>(t) << '\n';         // get using 0-based index
	std::get<2>(t) = 3.0;       // no set required: get returns a reference
	std::cout << std::get<double>(t) << '\n';    // get using unique type
	// std::cout << std::get<int>(t) << '\n';   --> ambiguous: compiler error!
	std::string s1 = std::get<3>(std::move(t));   // move a value out of a tuple


	{
		// Deconstructing a tuple using C++17 structured bindings
		auto [one, two, three, s2] = t; // = std::move(t) moves string into s
	}

	{
		// Deconstructing a tuple using std::tie()
		int one, two;
		std::string s2;
		std::tie(one, two, std::ignore, s2) = t; // = std::move(t) moves to s
	}

	{
		std::cout << std::tuple_size<decltype(t)>::value << '\n';       // 4
		std::tuple_element<0, decltype(t)>::type one = std::get<0>(t);  // int
		std::cout << one << std::endl;
	}

	std::cout << std::endl;
}
