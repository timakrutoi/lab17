#include "matrix.h"

template<typename T>
void test_(matrix<T>& m, T arg) {
	m.set(arg);
	std::cout << m << std::endl;
	m = m + m;
	std::cout << m << std::endl;
	std::cout << "===========================" << std::endl << std::endl;
}

int main() {
	try {
		matrix<int> m_int(10, 6);
		//matrix<double> m_double(3, 5);
		//matrix<char> m_char(3, 5);
		//matrix<point> m_point(3, 5);

		test_(m_int, 9);
		//test_(m_double, 3.14);
		//test_(m_char, 'A');
		//test_(m_point, point(3));
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what();
	}

	return 0;
}