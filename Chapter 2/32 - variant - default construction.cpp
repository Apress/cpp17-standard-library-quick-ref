#include <iostream>
#include <variant>

class NoDefaultCtor {
public:
	NoDefaultCtor() = delete;
	NoDefaultCtor(int) {}
};

int main()
{
	std::variant<std::monostate, NoDefaultCtor> v;
}
