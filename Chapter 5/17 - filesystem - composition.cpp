#include <iostream>
#include <filesystem>

auto get_full_path(int ind) {
	auto temp_dir = std::filesystem::path(LR"(c:\temp)");
	auto full_path = temp_dir / u8"file";     // or "file", L"file", etc.
	full_path += std::to_string(ind) + ".log";// or full_path.append(...);
	return full_path;
}

int main()
{
	std::cout << get_full_path(10) << std::endl;

	using std::filesystem::path;
	std::cout << path("foo") / "bar" << '\n';      // "foo/bar" or "foo\\bar"
	std::cout << path("foo") / "/bar" << '\n';     // "/bar"
	std::cout << path("foo") / "c:/bar" << '\n';   // "c:/bar" (Windows)
	std::cout << path("c:/foo") / "d:bar" << '\n'; // "d:bar" (Windows)
	std::cout << path("c:/foo") / "c:bar" << '\n'; // "c:/foo\\bar" (Windows)
	std::cout << path("c:/foo") / "/bar" << '\n';  // "c:/bar" (Windows)
}
