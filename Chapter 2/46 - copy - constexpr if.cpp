#include <iostream>
#include <vector>
#include <string>
#include <cstring>	// for std::memcpy()

template<typename T, size_t N>
void copy(T(&from)[N], T(&to)[N])
{
	if constexpr (std::is_trivially_copyable_v<T>) {
		std::memcpy(to, from, N * sizeof(T));
	} else {
		for (size_t i = 0; i < N; ++i) to[i] = from[i];
	}
}


int main()
{
	int arrayFrom[12] = { 0 };
	int arrayTo[12] = { 0 };
	copy(arrayFrom, arrayTo);	// Calls the first copy() implementation.

	std::string vecFrom[2] = { "A", "B" };
	std::string vecTo[2];
	copy(vecFrom, vecTo);		// Calls the second copy() implementation.


	std::cout << std::endl;
}
