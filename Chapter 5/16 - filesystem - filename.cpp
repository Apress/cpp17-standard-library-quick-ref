#include <iostream>
#include <filesystem>

int main()
{
	using std::filesystem::path;
	std::cout << path(R"(c:\Temp)").filename() << std::endl;  // "Temp"
	std::cout << path(R"(c:\Temp\)").filename() << std::endl; // ""
}
