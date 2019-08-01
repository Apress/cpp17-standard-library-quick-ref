#pragma once

#include <string>
#include <ostream>

class Person {
public:
	Person() = default;
	explicit Person(std::string first, std::string last = "",
		bool isVIP = false)
		: m_first(move(first)), m_last(move(last)), m_isVIP(isVIP) {}

	const std::string& GetFirstName() const { return m_first; }
	void SetFirstName(std::string first) { m_first = move(first); }

	const std::string& GetLastName() const { return m_last; }
	void SetLastName(std::string last) { m_last = move(last); }

	bool IsVIP() const { return m_isVIP; }

private:
	std::string m_first, m_last;
	bool m_isVIP = false;
};

// Comparison operator
bool operator<(const Person& lhs, const Person& rhs) {
	if (lhs.IsVIP() != rhs.IsVIP()) return rhs.IsVIP();
	if (lhs.GetLastName() != rhs.GetLastName())
		return lhs.GetLastName() < rhs.GetLastName();
	return lhs.GetFirstName() < rhs.GetFirstName();
}

// Equality operator
bool operator==(const Person & lhs, const Person & rhs) {
	return lhs.IsVIP() == rhs.IsVIP()
		&& lhs.GetFirstName() == rhs.GetFirstName()
		&& lhs.GetLastName() == rhs.GetLastName();
}

// Stream insertion operator for output to C++ streams.
// Details of this operator can be found in Chapter 5.
std::ostream& operator<<(std::ostream & os, const Person & person) {
	return os << person.GetFirstName() << ' ' << person.GetLastName();
}
