#include <iostream>
#include <regex>
#include <string>

int main()
{
	const std::string csv = "a, b, c,123";
	const std::regex regex(R"(\s*,\s*)");
	std::sregex_token_iterator beg(begin(csv), end(csv), regex, -1), end;
	std::for_each(beg, end, [](auto & token) { std::cout << token << '\n'; });
}
