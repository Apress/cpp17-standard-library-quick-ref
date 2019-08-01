#include <iostream>
#include <filesystem>

int main()
{
	std::filesystem::path my_path("c:/Windows/notepad.exe");
	for (const std::filesystem::path& element : my_path)
		std::cout << element << ", ";


	std::cout << std::endl;
}
