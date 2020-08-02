#pragma once


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
