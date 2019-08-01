#include <iostream>
#include <vector>

template<typename, typename = std::void_t<>>
struct has_value_type : std::false_type {};

template<typename T>
struct has_value_type<T, std::void_t<typename T::value_type>>
	: std::true_type {};

template<typename T>
inline constexpr bool has_value_type_v = has_value_type<T>::value;

int main()
{
	// All containers (Chapter 3) define a value_type type alias (example
	// needs the <vector> header), as does std::integral_constant itself:
	static_assert(has_value_type<std::vector<int>>::value);
	static_assert(!has_value_type_v<int>);
	static_assert(has_value_type<has_value_type<int>>{});
}
