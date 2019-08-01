#include <iostream>
#include <memory>
#include "../Common/Person.h"


int main()
{
	std::allocator<Person> allocator;   // Default allocator
	Person* p = allocator.allocate(1);  // Person constructor not invoked
	new(p) Person("Basil", "Fawlty");   // Initialize using placement new 
	p->~Person();                       // Memory not deallocated yet
	allocator.deallocate(p, 1);

}
