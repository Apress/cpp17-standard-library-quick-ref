#include <iostream>
#include <unordered_set>
#include "../Common/Person.h"

namespace std {
	template<> struct hash<Person> {
		// The requirement to add the following two type aliases
		// is deprecated in C++17 (and expected to be removed in C++20)
		using argument_type = Person;
		using result_type = std::size_t;

		result_type operator()(const argument_type& p) const {
			auto firstNameHash(std::hash<std::string>()(p.GetFirstName()));
			auto lastNameHash(std::hash<std::string>()(p.GetLastName()));
			return firstNameHash ^ lastNameHash;
		}
	};
}

int main()
{
	std::unordered_set<Person> persons;
	persons.insert(Person("John", "Doe"));
}
