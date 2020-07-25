#pragma once
#include <iostream>

template<typename T>
class Matrix {
private:
	size_t size_x, size_y;
	T** data;
public:
	Matrix() { size_x = 0; size_y = 0; data = NULL; };
	Matrix(const Matrix& m);
	Matrix(size_t row, size_t column);
	~Matrix();

	void set(size_t x, size_t y, T value);
	void set1(T val);
	const T get(size_t x, size_t y);

	const size_t rows();
	const size_t columns();

	Matrix operator+(const Matrix& m);
	Matrix& operator=(const Matrix& m);

	friend std::ostream& operator<<(std::ostream& out, Matrix<T>& matrix) { // このはくそです。
		for (size_t i = 0; i < matrix.rows(); i++) {
			out << "[ ";
			for (size_t j = 0; j < matrix.columns(); j++) {
				out << matrix.get(i, j) << " ";
			}
			out << "]" << std::endl;
		}
		return out;
	}
};