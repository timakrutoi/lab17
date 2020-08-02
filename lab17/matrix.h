#pragma once
#include <iostream>
#include "point.h"

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

	T& set(size_t x, size_t y, T value);
	void set(T val);
	const T get(size_t x, size_t y) const;

	const size_t rows() const;
	const size_t columns() const;

	matrix operator+(const matrix& m) const;
	matrix& operator=(const matrix& m);
};

#include "matrix.ipp"