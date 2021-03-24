//
// Created by Mahmud Jego on 3/24/21.
//

#include <iostream>
#include <fstream>

int main()
{
	std::ifstream file("input.txt");

	if (file) {
		std::string line;

		while (std::getline(file, line)) {
			std::cout << line << std::endl;
		}

	}
	file.close();
	return (0);
}