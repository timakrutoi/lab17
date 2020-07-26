#include "matrix.h"

template<typename T>
inline matrix<T>::matrix(size_t row, size_t column) {
	try{
		size_x = column; size_y = row;
		data = new T * [size_x];

		for (size_t i = 0; i < size_x; i++) {
			data[i] = new T[size_y];
			for (size_t j = 0; j < size_y; j++) {
				data[i][j] = 0;
			}
		}
	}
	catch (std::bad_alloc& exception) {
		throw "Error: bad_alloc detected";
	}
}

template<typename T>
matrix<T>::matrix(const matrix& m) {
	try{
		size_x = m.size_x; size_y = m.size_y;
		data = new T * [size_x];

		for (size_t i = 0; i < size_x; i++) {
			data[i] = new T[size_y];
			for (size_t j = 0; j < size_y; j++) {
				data[i][j] = m.data[i][j];
			}
		}
	}
	catch (std::bad_alloc& exception) {
		throw "Error: bad_alloc detected";
	}
}

template<typename T>
void matrix<T>::set(size_t x, size_t y, T value) {
	if (x >= size_x || y >= size_y) throw "Error: invalid args";

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
	if (x >= size_x || y >= size_y) throw "Error: invalid args";

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
	if (!(size_x == m.size_x && size_y == m.size_y)) throw "Error: matrix must be equal sizes to do '*'";

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
	for (size_t i = 0; i < size_x; i++) {
		delete[] data[i];
	}
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
	catch (std::bad_alloc& exception) {
		throw "Error: bad_alloc detected";
	}

	return *this;
}

//template<typename T>
//std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix) {
//	for (size_t i = 0; i < matrix.rows(); i++) {
//		out << "[ ";
//		for (size_t j = 0; j < matrix.columns(); j++) {
//			out << matrix.get(i, j) << " ";
//		}
//		out << "]" << endl;
//	}
//	return out;
//}

template<typename T>
matrix<T>::~matrix() {
	for (size_t i = 0; i < size_x; i++) {
		delete[] data[i];
	}

	delete[] data;
    data = nullptr;
}
