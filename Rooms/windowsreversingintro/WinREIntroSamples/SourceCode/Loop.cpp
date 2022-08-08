#include <iostream>
#include <string>

int main() {
	size_t count = 0;
	std::string input;

	std::cout << "String: ";
	std::cin >> input;
	
	for (size_t x = 0; x < input.length(); x++) {
		if (input[x] >= 'a' && input[x] <= 'z') {
			count++;
		}
	}
	std::cout << "Counted " << count << " lowercase characters.\n";
	
	return 0;
}