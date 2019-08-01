#include <iostream>
#include <typeinfo>

using namespace std;

template<typename T> struct my_decay {
private:
	using U = remove_reference_t<T>;
public:
	using type = conditional_t<is_array_v<U>, remove_extent_t<U>*,
		conditional_t<is_function_v<U>, add_pointer_t<U>,
		remove_cv_t<U>>>;
};

int main()
{
	std::cout << typeid(my_decay<int&&>::type).name() << '\n';			// int
	std::cout << typeid(my_decay<const int[12]>::type).name() << '\n';	// const int *


	std::cout << std::endl;
}
