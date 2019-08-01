#include <iostream>
#include <map>
#include "../Common/Person.h"

int main()
{
	std::map<Person, int> myMap{ { Person("Marc"), 1 }, { Person("Bart"), 2 } };
	std::map<Person, int> myOtherMap;

	auto node = myMap.extract(Person("Marc")); // type std::map::node_type
	if (node)                                  // or: !node.empty()
		myOtherMap.insert(std::move(node));    // would ignore empty node


	std::cout << std::endl;
}
