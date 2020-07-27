#include "matrix.h"

template<typename T>
inline matrix<T>::matrix(size_t row, size_t column) {
	try{
		size_x = column; size_y = row;
		data = new T * [size_x];
		T* raw_data = new T[size_x * size_y];

		for (size_t i = 0; i < size_x; i++) {
			data[i] = raw_data + i * size_y;
			for (size_t j = 0; j < size_y; j++) {
				data[i][j] = 0;
			}
		}
	}
	catch (std::bad_alloc&) {
		delete[] data[0];
		delete[] data;

		throw;
	}
}

template<typename T>
matrix<T>::matrix(const matrix& m) {
	try{
		size_x = m.size_x; size_y = m.size_y;
		data = new T * [size_x];
		T* raw_data = new T[size_x * size_y];

		for (size_t i = 0; i < size_x; i++) {
			data[i] = raw_data + i * size_y;
			for (size_t j = 0; j < size_y; j++) {
				data[i][j] = m.data[i][j];
			}
		}
	}
	catch (std::bad_alloc&) {
		delete[] data[0];
		delete[] data;
		
		throw;
	}
}

template<typename T>
void matrix<T>::set(size_t x, size_t y, T& value) {
	if (x >= size_x || y >= size_y) throw std::out_of_range("Invalid args( set )");

	data[x][y] = value;
}

template<typename T>
void matrix<T>::set1(T val) {
	for (size_t i = 0; i < size_x; i++) {
		for (size_t j = 0; j < size_y; j++) {
			data[i][j] = val;
		}
	}
}

template<typename T>
const T matrix<T>::get(size_t x, size_t y) const {
	if (x >= size_x || y >= size_y) throw std::out_of_range("Invalid args( get )");

	return data[x][y];
}

template<typename T>
const size_t matrix<T>::rows() const {
	return size_y;
}

template<typename T>
const size_t matrix<T>::columns() const {
	return size_x;
}

template<typename T>
matrix<T> matrix<T>::operator+(const matrix& m) const {
	if (!(size_x == m.size_x && size_y == m.size_y)) throw std::logic_error("Matrices must be equal sizes to do '+'");

	matrix<T> temp(*this);

	for (size_t i = 0; i < size_x; i++) {
		for (size_t j = 0; j < size_y; j++) {
			temp.data[i][j] = temp.data[i][j] + m.data[i][j];
		}
	}

	return temp;
}

template<typename T>
matrix<T>& matrix<T>::operator=(const matrix& m) {
	if (this == &m) return *this;
	delete[] data[0];
	delete[] data;

	try {
		size_x = m.size_x; size_y = m.size_y;
		data = new T * [size_x];

		for (size_t i = 0; i < size_x; i++) {
			data[i] = new T[size_y];
			for (size_t j = 0; j < size_y; j++) {
				data[i][j] = m.data[i][j];
			}
		}
	}
	catch (std::bad_alloc&) {
		for (size_t i = 0; i < size_x; i++) {
			delete[] data[i];
		}
		delete[] data;
		
		throw;
	}

	return *this;
}

template<typename T>
matrix<T>::~matrix() {
	if (!data) return;

	delete[] data[0];
	delete[] data;

	data = nullptr;
}
