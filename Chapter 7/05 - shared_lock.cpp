#include <iostream>
#include <shared_mutex>
#include <thread>
#include <string>

class ConcurrentPerson {
public:
	// ...
	std::string GetFirstName() const { // Don’t return reference to m_first!
		std::shared_lock lock(m_mutex);
		return m_first;
	}
	void SetFirstName(std::string first) {
		std::unique_lock lock(m_mutex);
		m_first = std::move(first);
	}
	// ...	
private:
	mutable std::shared_mutex m_mutex; // mutable for use in const members
	std::string m_first;
	// ...
};


int main()
{
}
