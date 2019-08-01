#include <iostream>
#include <variant>
#include <string>

class MyVisitor {
public:
	auto operator()(int, int) const { return "Two ints."; }
	auto operator()(const std::string&, const std::string&) const {
		return "Two strings.";
	}
	auto operator()(const std::string&, int) const {
		return "A string and an int.";
	}
	auto operator()(int, const std::string&) const {
		return "An int and a string.";
	}
};

int main()
{
	std::variant<std::string, int> v1 = { "Hello world!" }, v2 = 42;

	// A simple visitor.
	auto myVisitor = [](auto && value) { std::cout << value << std::endl; };
	std::visit(myVisitor, v1);  // Hello world!
	std::visit(myVisitor, v2);  // 42

	// A type-matching visitor to handle specific types.
	struct IsNullVisitor {
		bool operator()(const std::string& s) const { return s.empty(); }
		bool operator()(int i) const { return i == 0; }
	};

	std::cout << std::visit(IsNullVisitor{}, v1) << std::endl; // 0
	std::cout << std::visit(IsNullVisitor{}, v2) << std::endl; // 0

	// An int and a string.
	std::cout << std::visit(MyVisitor{}, v1, v2) << std::endl;
}
