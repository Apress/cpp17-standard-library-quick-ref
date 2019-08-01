#include <iostream>
#include <map>
#include "../Common/Person.h"

int main()
{
	std::map<Person, int> myMap{ { Person("Jenne"), 1 },{ Person("Bart"), 2 } };


	auto iter = begin(myMap);  // type of *iter is pair<const Person, int>&
	std::cout << "Key=" << iter->first.GetFirstName();    // Key=Bart
	std::cout << ", Value=" << iter->second << std::endl; // , Value=2


	myMap[Person("Bart")] = 0;
	std::cout << myMap[Person("Bart")] << std::endl;   // 0


	myMap.erase(Person("Bart"));


	myMap[Person("Peter")] = 3;


	myMap.insert(std::pair(Person("Marc"), 4));
	myMap.insert({ Person("Marc"), 4 });


	myMap.insert({ Person("Marc"), 5 });              // 5 is discarded
	std::cout << myMap[Person("Marc")] << std::endl;  // still 4!


	myMap.insert_or_assign(Person("Marc"), 5);
	std::cout << myMap[Person("Marc")] << std::endl;  // 5


	std::map<int, Person> inverseMap;
	inverseMap.insert({ 3, Person("Peter", "Van Weert") });
	inverseMap.insert_or_assign(5, Person("Marc", "Gregoire"));


	inverseMap.emplace(6, Person("Christophe", "Pichaud"));
	inverseMap.emplace(std::piecewise_construct, std::forward_as_tuple(6),
		std::forward_as_tuple("Christophe", "Pichaud"));
	inverseMap.try_emplace(6, "Christophe", "Pichaud");


	Person powers("Mark", "Powers");
	inverseMap.emplace(6, std::move(powers));


	{
		auto [iter, inserted] = inverseMap.insert({ 6, Person("Marc") });
		if (!inserted)
			std::cout << "Not inserted. Existing value: " << iter->second;
	}


	std::cout << std::endl;
}
