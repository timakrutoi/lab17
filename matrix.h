#pragma once
#include <iostream>

template<typename T>
class matrix {
private:
	size_t size_x, size_y;
	T** data;
public:
	matrix() { size_x = 0; size_y = 0; data = nullptr; };
	matrix(const matrix& m);
	matrix(size_t row, size_t column);
	~matrix();

	void set(size_t x, size_t y, T value);
	void set1(T val);
	const T get(size_t x, size_t y) const;

	const size_t rows() const;
	const size_t columns() const;

	matrix operator+(const matrix& m) const;
	matrix& operator=(const matrix& m);

};

template<typename T>
std::ostream& operator<<(std::ostream& out, matrix<T>& matrix) {
	for (size_t i = 0; i < matrix.rows(); i++) {
		out << "[ ";
		for (size_t j = 0; j < matrix.columns(); j++) {
			out << matrix.get(i, j) << " ";
		}
		out << "]" << std::endl;
	}
	return out;
}

#include "matrix.ipp"