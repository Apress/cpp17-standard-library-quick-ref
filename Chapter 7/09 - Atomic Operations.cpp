#include <iostream>
#include <atomic>

int main()
{
	{
		std::atomic_int atom;	    // Uninitialized!
	}


	{
		std::atomic_int atom{ -123 };         // -123
		atom = 456;
		std::cout << atom << std::endl;        // 456


		atom.store(123);
		std::cout << atom.load() << std::endl; // 123
	}
}
