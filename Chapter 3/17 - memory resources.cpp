#include <iostream>
#include <memory>
#include <memory_resource>
#include <string>


int main()
{
	char buffer[300];   // Static allocation on the stack
	std::pmr::monotonic_buffer_resource resource(
		buffer, std::size(buffer), std::pmr::null_memory_resource()
	);
	std::pmr::string short_string(&resource);
	// ... fill and manipulate short_string
}
