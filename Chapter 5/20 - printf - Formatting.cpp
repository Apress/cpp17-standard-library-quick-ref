#include <cstdio>
#include <string>

using namespace std;

int main()
{
	int i = 123;
	std::printf("i: '%+10d'\n", i);                // i: '      +123'

	long double d = 31.415;
	int prec = 4;       /* precision */
	std::printf("d: %.4Lf = %.*Le\n", d, prec, d); // d: 31.4150 = 3.1415e+01
}
