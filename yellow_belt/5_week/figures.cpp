//
// Created by Mahmud Jego on 4/21/21.
//

#include <iostream>
#include <vector>
#include <istream>
#include <memory>
#include <sstream>
#include <iomanip>
#include <cmath>

class Figure {
public:
	Figure() {}
	virtual std::string Name() = 0;
	virtual double Perimeter() = 0;
	virtual double Area() = 0;
};

class Rect : public Figure {
public:
	Rect(const double perimeter, const double area)
			: _name("RECT"), _perimeter(perimeter), _area(area) {}

	std::string Name() override { return _name; }
	double Perimeter() override { return _perimeter; }
	double Area() override { return _area; }

private:
	std::string _name;
	double _perimeter, _area;
};

class Triangle : public Figure {
public:
	Triangle (const double perimeter, const double area)
			: _name("TRIANGLE"), _perimeter(perimeter), _area(area) {}

	std::string Name() override { return _name; }
	double Perimeter() override { return _perimeter; }
	double Area() override { return _area; }

private:
	std::string _name;
	double _perimeter, _area;
};

class Circle : public Figure {
public:
	Circle (const double perimeter, const double area)
			: _name("CIRCLE"), _perimeter(perimeter), _area(area) {}

	std::string Name() override { return _name; }
	double Perimeter() override { return _perimeter; }
	double Area() override { return _area; }

private:
	std::string _name;
	double _perimeter, _area;
};

std::shared_ptr<Figure> CreateFigure(std::istringstream& is) {
	std::string name;
	double a, b, c;
	is >> name;

	if (name == "RECT") {
		is >> a >> b;
		return std::make_shared<Rect>((a + b) * 2, a * b);
	} else if (name == "TRIANGLE") {
		is >> a >> b >> c;
		double pp = (a + b + c) / 2;
		double area = sqrt(pp * (pp - a) * (pp - b) * (pp - c));
		return std::make_shared<Triangle>(a + b + c, area);
	} else if (name == "CIRCLE") {
		is >> a;
		return std::make_shared<Circle>(2 * 3.14 * a, 3.14 * pow(a, 2));
	} else {
		throw std::logic_error("not find type");
	}
}

int main() {
	std::vector<std::shared_ptr<Figure>> figures;
	for (std::string line; getline(std::cin, line); ) {
		std::istringstream is(line);

		std::string command;
		is >> command;
		if (command == "ADD") {
			// Пропускаем "лишние" ведущие пробелы.
			// Подробнее об std::ws можно узнать здесь:
			// https://en.cppreference.com/w/cpp/io/manip/ws
			is >> std::ws;
			figures.push_back(CreateFigure(is));
		} else if (command == "PRINT") {
			for (const auto& current_figure : figures) {
				std::cout << std::fixed << std::setprecision(3)
					 << current_figure->Name() << " "
					 << current_figure->Perimeter() << " "
					 << current_figure->Area() << std::endl;
			}
		}
	}
	return 0;
}