#ifdef MATRIX_H

template<typename T>
inline matrix<T>::matrix(size_t row, size_t column) {
	try{
		size_x = row; size_y = column;
		data = new T * [size_x];
		T* raw_data = new T[size_x * size_y];
		std::memset(raw_data, 0, size_x * size_y);

		for (size_t i = 0; i < size_x; i++) {
			data[i] = raw_data + i * size_y;
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
		delete[] data;
		
		throw;
	}
}

template<typename T>
void matrix<T>::set(size_t row, size_t column, T& value) {
	if (row >= size_x || column >= size_y) throw std::out_of_range("Invalid args( set )");

	data[row][column] = value;
}

template<typename T>
void matrix<T>::set(T val) {
	for (size_t i = 0; i < size_x; i++) {
		for (size_t j = 0; j < size_y; j++) {
			data[i][j] = val;
		}
	}
}

template<typename T>
const T matrix<T>::get(size_t row, size_t column) const {
	if (row >= size_x || column >= size_y) throw std::out_of_range("Invalid args ( get )");

	return data[row][column];
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
		T* raw_data = new T[size_x * size_y];

		for (size_t i = 0; i < size_x; i++) {
			data[i] = raw_data + i * size_y;
			for (size_t j = 0; j < size_y; j++) {
				data[i][j] = m.data[i][j];
			}
		}
	}
	catch (std::bad_alloc&) {
		delete[] data;
		
		throw;
	}

	return *this;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, matrix<T>& matrix) {
	out << "[ ";
	for (size_t i = 0; i < matrix.rows() * matrix.columns(); i++) {
		if (i % matrix.columns() == 0 && i > 0) out << "]\n[ ";
		out << matrix.get(i / matrix.rows(), i / matrix.columns()) << " ";
	}
	out << "]" << std::endl;
	return out;
}

template<typename T>
matrix<T>::~matrix() {
	if (!data) return;

	delete[] data[0];
	delete[] data;

	data = nullptr;
}
#endif