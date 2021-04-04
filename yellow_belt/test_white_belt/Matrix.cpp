//
// Created by Makhmud Ego on 03.04.2021.
//
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

class Matrix {
public:
	Matrix() : _rows(0), _cols(0){}

	Matrix(int numRows, int numCols) {
		Reset(numRows, numCols);
	}

	int GetNumRows() const {
		return _rows;
	}
	int GetNumColumns() const {
		return _cols;
	}

	void Reset(int numRows, int numCols) {
		if (numCols < 0 || numRows < 0)
			throw std::out_of_range("negative arg");
		if (numCols == 0 || numRows == 0)
			this->_cols = this->_rows = 0;
		else {
			this->_cols = numCols;
			this->_rows = numRows;
		}
		_matrix.clear();
		_matrix.resize(this->_rows);
		for (auto &item : _matrix) {
			item.resize(this->_cols);
		}
	}

	int At(int numRows, int numCols) const {
		if (numRows < 0 || numCols < 0 || _rows <= numRows || _cols <= numCols)
			throw std::out_of_range("no valid arg");
		return _matrix[numRows][numCols];
	}

	int& At(int numRows, int numCols) {
		if (numRows < 0 || numCols < 0 || _rows <= numRows || _cols <= numCols)
			throw std::out_of_range("no valid arg");
		return _matrix[numRows][numCols];
	}

	Matrix operator+(const Matrix& other) const {
		if (this->_rows != other._rows || this->_cols != other._cols)
			throw std::invalid_argument("unequal");
		Matrix matrix(this->_rows, this->_cols);
		for (int i = 0; i < matrix._matrix.size(); ++i) {
			for (int j = 0; j < matrix._matrix[i].size(); ++j) {
				matrix._matrix[i][j] = this->_matrix[i][j] + other._matrix[i][j];
			}
		}
		return matrix;
	}

	bool operator==(const Matrix& other) const {
		return this->_matrix == other._matrix;
	}
private:
	std::vector<std::vector<int> > _matrix;
	int _rows;
	int _cols;
};

std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
	os << matrix.GetNumRows() << ' ' << matrix.GetNumColumns() << std::endl;
	for (int i = 0; i < matrix.GetNumRows(); ++i) {
		for (int j = 0; j < matrix.GetNumColumns(); ++j) {
			os << matrix.At(i, j);
			if (j < matrix.GetNumColumns() - 1)
				os << ' ';
		}
		if (i < matrix.GetNumRows() - 1)
			os << std::endl;
	}
	return os;
}

std::istream &operator>>(std::istream &is, Matrix& matrix) {
	int rows, cols;
	is >> rows >> cols;
	matrix.Reset(rows, cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			is >> matrix.At(i, j);
		}
	}
	return is;
}

int main() {
	Matrix one;
	Matrix two;

	std::cin >> one >> two;
	std::cout << one + two << std::endl;
	return 0;
}