//
// Created by Mahmud Jego on 3/24/21.
//

#include <iostream>
#include <fstream>

int main()
{
	std::ifstream file("input.txt");
	std::ofstream ofs("output.txt");

	if (file) {
		std::string line;

		while (std::getline(file, line)) {
			ofs << line << std::endl;
		}

	}
	file.close();
	ofs.close();
	return (0);
}