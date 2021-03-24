//
// Created by Mahmud Jego on 3/24/21.
//

#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
	std::ifstream file("input.txt");

	if (file) {
		double line;

		while (file >> line) {
			std::cout << std::fixed << std::setprecision(3) << line << std::endl;
		}

	}
	file.close();
	return (0);
}