#define _CRT_SECURE_NO_WARNINGS		// To make the example work with Visual C++.
#include <cstdio>
#include <string>

int main()
{
	std::string s = "i: +123; d: -2.34E-3; chars: abcdef";
	int i = 0; double d = 0.0; char chars[4] = { 0 };
	std::sscanf(s.c_str(), "i: %i; d: %lE; chars: %[abc]", &i, &d, chars);
	std::printf("i: %+i; d: %.2lE; chars: %s", i, d, chars);

	std::printf("\n");
}
