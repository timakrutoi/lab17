#pragma once
#include <iostream>

template<typename T>
class Matrix {
private:
	size_t size_x, size_y;
	T** data;
public:
	Matrix() { size_x = 0; size_y = 0; data = nullptr; };
	Matrix(const Matrix& m);
	Matrix(size_t row, size_t column);
	~Matrix();

	void set(size_t x, size_t y, T value);
	void set1(T val);
	const T get(size_t x, size_t y) const;

	const size_t rows() const;
	const size_t columns() const;

	Matrix operator+(const Matrix& m) const;
	Matrix& operator=(const Matrix& m);

};

template<typename T>
std::ostream& operator<<(std::ostream& out, Matrix<T>& matrix) {
	for (size_t i = 0; i < matrix.rows(); i++) {
		out << "[ ";
		for (size_t j = 0; j < matrix.columns(); j++) {
			out << matrix.get(i, j) << " ";
		}
		out << "]" << std::endl;
	}
	return out;
}

#include "matrix.tpp"