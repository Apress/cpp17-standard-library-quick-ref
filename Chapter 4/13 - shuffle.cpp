#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>

int main()
{
	std::random_device seeder;
	const auto seed = seeder.entropy() ? seeder() : std::time(nullptr);
	std::default_random_engine gen(
		static_cast<std::default_random_engine::result_type>(seed));
	std::vector<int> in{ 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> out(6);
	std::sample(begin(in), end(in), begin(out), size(out), gen);	// Possible result: 1 3 4 7 9 10
	std::shuffle(begin(out), end(out), gen);						// Possible result: 3 10 9 7 4 1

	std::cout << std::endl;
}
