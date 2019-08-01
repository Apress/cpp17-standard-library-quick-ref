#define _ENABLE_ATOMIC_ALIGNMENT_FIX 1  // For Visual Studio

#include <iostream>
#include <atomic>
#include <array>

int main()
{
	std::atomic<float> fundamental;
	std::atomic<std::array<int, 2>> small_type;
	std::atomic<std::array<int, 100>> large_type;
	std::cout << std::boolalpha                      // Likely results:
		<< fundamental.is_lock_free() << '\n'  // true
		<< small_type.is_lock_free() << '\n'   // true
		<< large_type.is_lock_free() << '\n';  // false
}
