#include <iostream>
#include <string_view>

std::string_view extension(std::string_view fileName) {
	return fileName.substr(fileName.rfind('.') + 1);
}

int main()
{
	std::cout << extension("myfile.txt") << std::endl;
}
