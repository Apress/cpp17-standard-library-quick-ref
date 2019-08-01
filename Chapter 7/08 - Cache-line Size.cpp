#include <iostream>
#include <new>

struct Pod {
	int pea_1;
	// Possibly some other data members in between...
	int pea_2;
};


struct KeepApart {
	alignas(std::hardware_destructive_interference_size) float fire;
	alignas(std::hardware_destructive_interference_size) int ice;
};


int main()
{
	static_assert(sizeof(Pod) <= std::hardware_constructive_interference_size);
}
