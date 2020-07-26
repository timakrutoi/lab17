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


int main() {
	matrix<int> m_int(3, 3);
	matrix<double> m_double(3, 3);
	matrix<char> m_char(3, 3);
	matrix<point> m_point(3, 3);

	m_int.set1(9);
	m_double.set1(3.14);
	m_char.set1('A');
	m_point.set1(5);

	std::cout << m_int << std::endl;
	std::cout << m_double << std::endl;
	std::cout << m_char << std::endl;
	std::cout << m_point << std::endl;

	std::cout << "===================================================" << std::endl << std::endl;

	m_int = m_int + m_int;
	m_double = m_double + m_double;
	m_char = m_char + m_char;
	m_point = m_point + m_point;
	
	std::cout << m_int << std::endl;
	std::cout << m_double << std::endl;
	std::cout << m_char << std::endl;
	std::cout << m_point << std::endl;

	return 0;
}