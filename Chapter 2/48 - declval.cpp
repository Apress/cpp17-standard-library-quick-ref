#include <iostream>
#include <string>

template<typename T>
void process(const T& /*t*/)
{
	if constexpr (std::is_integral_v<decltype(std::declval<T>().handle())>)
		std::cout << "handle() has integral return type\n";
	else
		std::cout << "handle() has non-integral return type\n";
}

struct NoDefaultCtor { NoDefaultCtor(int) {}; int handle(); };
struct DefaultCtor { std::string handle(); };

int main()
{
	process(NoDefaultCtor{ 0 }); // handle() has integral return type
	process(DefaultCtor{});      // handle() has non-integral return type
}
