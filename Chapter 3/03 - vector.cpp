#include <iostream>
#include <vector>
#include <algorithm>
#include "../Common/Person.h"

int main()
{
	{
		std::vector<int> myVector1 = { 1,2,3,4 };
		std::vector<int> myVector2{ 1,2,3,4 };
	}


	{
		std::vector oneTwoThree{ 1,2,3 }; // <int> deduced from initializer list
		std::vector fiveFloats(5, 0.f);   // <float> deduced from 0.f
	}


	{
		std::vector<int> myVector(100, 12);

		myVector[1] = 22;
		std::cout << myVector[1] << '\n';  // 22
	}


	{
		std::vector<int> myVector;
		myVector.push_back(11);
		myVector.push_back(2);
	}


	{
		std::vector myVector{ 1,2,3,4 };
		myVector.insert(myVector.begin() + 2, 22); // 1,2,22,3,4
	}


	{
		std::vector myVector{ 1,2,3,4 };
		for (auto iter = myVector.begin(); iter != myVector.end(); ++iter)
		{
			if (*iter % 2 == 0)       // Duplicate all even values...
				iter = myVector.insert(iter + 1, *iter);
		}
	}


	{
		std::vector v1{ 1,2,3 };
		std::vector v2{ 4,5 };
		v1.insert(cbegin(v1) + 1, cbegin(v2), cend(v2)); // 1,4,5,2,3
		v1.insert(cend(v1), cbegin(v2), cend(v2));     // 1,4,5,2,3,4,5 (append!)


		v1.insert(cbegin(v1) + 1, { 4,5 });       // 1,4,5,2,3
		v1.insert(cend(v1), 2, 6);            // 1,4,5,2,3,6,6
	}


	{
		std::vector<Person> persons;
		persons.push_back(Person("Sheldon", "Cooper"));
		persons.emplace_back("Leonard", "Hofstadter");


		Person person("Howard", "Wolowitz");
		persons.push_back(std::move(person));
	}


	{
		std::vector<int> myVector;
		myVector.resize(100, 12);


		myVector.reserve(100);


		myVector.reserve(myVector.size() + 100);
	}


	{
		std::vector unlucky(100000, 13);   // Now reclaim unlucky's memory...
		{ std::vector<int> empty; empty.swap(unlucky); }


		std::vector<int>().swap(unlucky);     // (temporary is destroyed after ';')
	}


	{
		std::vector vec{ 1,2,3,2,2,6 };
		for (auto it = cbegin(vec); it != cend(vec);) {
			if (*it == 2)
				it = vec.erase(it);  // Returns iterator one past the removed item
			else
				++it;
		}
	}


	{
		std::vector vec{ 1,2,3,2,2,6 };                   // 1,2,3,2,2,6
		auto iter = std::remove(begin(vec), end(vec), 2); // 1,3,6,2,2,6
		vec.erase(iter, end(vec));                        // 1,3,6


		vec.erase(std::remove(begin(vec), end(vec), 2), end(vec));
	}


	std::cout << std::endl;
}
