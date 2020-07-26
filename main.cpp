#include "matrix.h"

typedef struct Point {
	int x, y, z;

	Point() {
		x = 0; y = 0; z = 0;
	}

	Point(int a) {
		x = a; y = a; z = a;
	}

	Point& operator+(const Point& p) {
		x += p.x;
		y += p.y;
		z += p.z;

		return *this;
	}	
}Point;

std::ostream& operator<<(std::ostream& out, const Point& p) {
	out << "(" << p.x << ";" << p.y << ";" << p.z << ")";
	return out;
}


int main() {
	Matrix<int> m_int(3, 3);
	Matrix<float> m_float(3, 3);
	Matrix<char> m_char(3, 3);
	Matrix<Point> m_point(3, 3);

	m_int.set1(9);
	m_float.set1(3.14);
	m_char.set1('A');
	m_point.set1(5);

	std::cout << m_int << std::endl;
	std::cout << m_float << std::endl;
	std::cout << m_char << std::endl;
	std::cout << m_point << std::endl;

	std::cout << "===================================================" << std::endl << std::endl;

	m_int = m_int + m_int;
	m_float = m_float + m_float;
	m_char = m_char + m_char;
	m_point = m_point + m_point;
	
	std::cout << m_int << std::endl;
	std::cout << m_float << std::endl;
	std::cout << m_char << std::endl;
	std::cout << m_point << std::endl;

	return 0;
}