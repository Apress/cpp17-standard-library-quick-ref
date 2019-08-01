#include <iostream>
#include <memory>

class MyObject : public std::enable_shared_from_this<MyObject>
{
public:
	std::shared_ptr<MyObject> pointer()
	{
		return shared_from_this();
	}
};


int main()
{
	auto p1 = std::make_shared<MyObject>();
	auto p2 = p1->pointer();
	auto p3 = p1->shared_from_this();

	try
	{
		MyObject unshared;
		auto p4 = unshared.shared_from_this(); // Throws std::bad_weak_ptr
	}
	catch (const std::bad_weak_ptr&)
	{
		std::cout << "Caught std::bad_weak_ptr\n";
	}


	std::cout << std::endl;
}
