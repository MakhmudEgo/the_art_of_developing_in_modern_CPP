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
		int n, m;
		file >> n >> m;
		file.ignore(1);

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				std::string tmp;
				if (j < m - 1)
					std::getline(file, tmp, ',');
				else
					std::getline(file, tmp);
				std::cout << std::fixed << std::setw(10) << tmp;
				if (j < m - 1)
					std::cout << ' ';
			}
			if (i < n -1)
				std::cout << std::endl;
		}
	}
	file.close();
	return (0);
}