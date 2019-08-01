#include <iostream>
#include <fstream>

int main()
{
	{
		std::ifstream in("nonexistent_file.ext");
		std::cout << in.fail() << std::endl;     // 1
	}


	{
		std::ifstream in("nonexistent_file.ext");
		try {
			in.exceptions(std::ios_base::failbit); // Raise exceptions on failure
		} catch (const std::ios_base::failure & exception) {
			std::cout << exception.what() << std::endl;
		}
	}


	std::cout << std::endl;
}
