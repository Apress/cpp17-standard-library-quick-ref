#include <iostream>
#include <locale>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	std::vector<std::string> strings = { "libert�", "�galit�", "fraternit�" };
	auto printSortedMotto = [&strings] {
		for (auto& s : strings) std::cout << s << ' ';
		std::cout << std::endl;
	};
	std::sort(begin(strings), end(strings));       // Lexicographic sort
	printSortedMotto();							   // fraternit� libert� �galit� 
	std::sort(begin(strings), end(strings), std::locale("french"));
	printSortedMotto();							   // �galit� fraternit� libert�


	std::cout << std::endl;
}
