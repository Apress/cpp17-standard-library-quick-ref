#include <iostream>
#include <set>

int main()
{
	std::set mySet{ 3,2,1 };   // std::set<int> deduced
	mySet.insert(2);
	mySet.insert(6);
	std::cout << mySet.size() << ' ' << *mySet.begin();    // 4 1


	std::cout << std::endl;
}
