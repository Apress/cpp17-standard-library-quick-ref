#include <iostream>
#include <fstream>

int main()
{
	std::string filename = "data.txt";
	std::fstream fs(filename);  // Default openmode=ios_base::in|ios_base::out
	if (!fs.good()) {           // Fail bit will be set if file does not exist
		fs.clear();             // First clear the error state
		fs.open(filename, std::ios_base::out); // Create the file
		fs.close();          // Close and reopen the file for input and output
		fs.open(filename, std::ios_base::in | std::ios_base::out);
	}


	std::cout << std::endl;
}
