#include <iostream>
#include <filesystem>

int main()
{
	// Print the names of all regular files in the current directory
	std::filesystem::directory_iterator begin("."), end;
	for (auto iter = begin; iter != end; ++iter) {
		if (iter->is_regular_file()) {
			std::cout << iter->path().filename() << '\n';
		}
	}


	std::cout << std::endl;


	for (auto& entry : std::filesystem::directory_iterator(".")) {
		if (entry.is_regular_file()) {
			std::cout << entry.path().filename() << '\n';
		}
	}


	std::cout << std::endl;


	for (auto& entry : std::filesystem::recursive_directory_iterator(".")) {
		if (entry.is_regular_file()) {
			std::cout << entry.path().filename() << '\n';
		}
	}
}
