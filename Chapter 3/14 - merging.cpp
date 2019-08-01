#include <iostream>
#include <set>

int main()
{
	std::multiset src{ 1, 2, 4 };
	std::set dst{ 2, 3 };
	dst.merge(src);
	// src == { 2 }
	// dst == { 1, 2, 3, 4 }
}
