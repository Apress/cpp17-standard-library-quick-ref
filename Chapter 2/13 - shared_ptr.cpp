#include <iostream>
#include <memory>
#include "../Common/Person.h"

int main()
{
	{
		auto bond = std::make_shared<int>(007);         // bond.use_count() == 1
		auto james = bond;    // james.use_count() == 2 && bond.use_count() == 2
		bond.reset();         // james.use_count() == 1 && bond.use_count() == 0
	}						  // 007 is deleted


	{
		auto muhammed = std::make_unique<Person>("Muhammed");
		std::shared_ptr<Person> mountain = std::move(muhammed);
		//muhammed = std::move(mountain); // mountain cannot be moved to Muhammed
	}

	std::cout << std::endl;
}
