//#include "matrix.h"
//
//template<typename T>
//inline Matrix<T>::Matrix(size_t row, size_t column) {
//	try{
//		size_x = column; size_y = row;
//		data = new T * [size_x];
//
//		for (size_t i = 0; i < size_x; i++) {
//			data[i] = new T[size_y];
//			for (size_t j = 0; j < size_y; j++) {
//				data[i][j] = 0;
//			}
//		}
//	}
//	catch (std::bad_alloc& exception) {
//		std::cerr << "Error: bad_alloc detected: " << exception.what();
//		exit(-4);
//	}
//}
//
//template<typename T>
//Matrix<T>::Matrix(const Matrix& m) {
//	try{
//		size_x = m.size_x; size_y = m.size_y;
//		data = new T * [size_x];
//
//		for (size_t i = 0; i < size_x; i++) {
//			data[i] = new T[size_y];
//			for (size_t j = 0; j < size_y; j++) {
//				data[i][j] = m.data[i][j];
//			}
//		}
//	}
//	catch (std::bad_alloc& exception) {
//		std::cerr << "Error: bad_alloc detected: " << exception.what();
//		exit(-4);
//	}
//}
//
//template<typename T>
//void Matrix<T>::set(size_t x, size_t y, T value) {
//	try {
//		if (x >= size_x || y >= size_y) throw 1;
//		if (x < 0 || y < 0) throw 1;
//	}
//	catch (int a) {
//		std::cerr << "Error: Invalid args";
//		return;
//	}
//	data[x][y] = value;
//}
//
//template<typename T>
//void Matrix<T>::set1(T val) {
//	for (size_t i = 0; i < size_x; i++) {
//		for (size_t j = 0; j < size_y; j++) {
//			data[i][j] = val;
//		}
//	}
//}
//
//template<typename T>
//const T Matrix<T>::get(size_t x, size_t y) const {
//	try {
//		if (x >= size_x || y >= size_y) throw 1;
//		if (x < 0 || y < 0) throw 1;
//	}
//	catch (int a) {
//		std::cerr << "Error: Invalid args";
//		exit(-a);
//	}
//	return data[x][y];
//}
//
//template<typename T>
//const size_t Matrix<T>::rows() const {
//	return size_y;
//}
//
//template<typename T>
//const size_t Matrix<T>::columns() const {
//	return size_x;
//}
//
//template<typename T>
//Matrix<T> Matrix<T>::operator+(const Matrix& m) const {
//	try {
//		if (!(size_x == m.size_x && size_y == m.size_y)) throw 2;
//	}
//	catch (int a) {
//		std::cerr << "Error: Matrix must be equal sizes";
//		exit(-a);
//	}
//	Matrix<T> temp(*this);
//
//	for (size_t i = 0; i < size_x; i++) {
//		for (size_t j = 0; j < size_y; j++) {
//			temp.data[i][j] = temp.data[i][j] + T(m.data[i][j]);
//		}
//	}
//
//	return temp;
//}
//
//template<typename T>
//Matrix<T>& Matrix<T>::operator=(const Matrix& m) {
//	for (size_t i = 0; i < size_x; i++) {
//		delete[] data[i];
//	}
//	delete[] data;
//
//	try {
//		size_x = m.size_x; size_y = m.size_y;
//		data = new T * [size_x];
//
//		for (size_t i = 0; i < size_x; i++) {
//			data[i] = new T[size_y];
//			for (size_t j = 0; j < size_y; j++) {
//				data[i][j] = m.data[i][j];
//			}
//		}
//	}
//
//	catch (std::bad_alloc& exception) {
//		std::cerr << "Error: bad_alloc detected: " << exception.what();
//		exit(-4);
//	}
//
//	return *this;
//}
//
////template<typename T>
////std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix) {
////	for (size_t i = 0; i < matrix.rows(); i++) {
////		out << "[ ";
////		for (size_t j = 0; j < matrix.columns(); j++) {
////			out << matrix.get(i, j) << " ";
////		}
////		out << "]" << endl;
////	}
////	return out;
////}
//
//template<typename T>
//Matrix<T>::~Matrix() {
//	for (size_t i = 0; i < size_x; i++) {
//		delete[] data[i];
//	}
//
//	delete[] data;
//}
