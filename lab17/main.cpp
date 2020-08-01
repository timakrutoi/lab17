#include "matrix.h"

typedef struct point {
	int x, y, z;

	point() {
		x = 0; y = 0; z = 0;
	}

	point(int a) {
		x = a; y = a; z = a;
	}

	point& operator+(const point& p) {
		x += p.x;
		y += p.y;
		z += p.z;

		return *this;
	}	
}Point;

std::ostream& operator<<(std::ostream& out, const point& p) {
	out << "(" << p.x << ";" << p.y << ";" << p.z << ")";
	return out;
}

template<typename T>
void test_(matrix<T>& m, T arg) {
	m.set(arg);
	std::cout << m << std::endl;
	//m = m + m;
	std::cout << m << std::endl;
	std::cout << "===========================" << std::endl << std::endl;
}

int main() {
	try {
		matrix<int> m_int(6, 30);
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