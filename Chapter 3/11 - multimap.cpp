#include <iostream>
#include <map>
#include <string>

int main()
{
	std::multimap<std::string, int> myMulti;
	myMulti.insert({ "someKey", 2 });
	myMulti.insert({ "sameKey", 5 });
	myMulti.insert({ "sameKey", 2 });
	std::cout << myMulti.size() << ' ' << myMulti.begin()->second;  // 3 5


	std::cout << std::endl;
}
