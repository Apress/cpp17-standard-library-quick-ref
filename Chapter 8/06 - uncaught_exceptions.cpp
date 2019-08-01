#include <iostream>

class Guard {
	const int exception_count = std::uncaught_exceptions();
public:
	~Guard() {
		std::cout << (exception_count == std::uncaught_exceptions()
			? "~Guard() invoked normally\n"
			: "~Guard() invoked during stack unwinding\n");
	}
};


int main()
{
}
