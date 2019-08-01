#include <iostream>
#include <atomic>
#include "../Common/Person.h"

int main()
{
	{
		std::atomic<Person*> person(new Person("Phil"));  // non-atomic init.
		// ... (share references to person with other threads)
		person = new Person("Claire");         // atomic store
		person.load()->SetLastName("Dunphy");  // atomic load, non-atomic setter!
	}


	{
		std::atomic<Person*> atomic_person(nullptr);
		// ... (share references to atomic_person with other threads)
		auto person = new Person();
		person->SetFirstName("Jay");
		person->SetLastName("Pritchett");
		atomic_person = person;        // atomic store + release fence!

		// ...

		auto p = atomic_person.exchange(nullptr);
		delete p;
	}


	std::cout << std::endl;
}
