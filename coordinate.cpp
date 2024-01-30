#include "coordinate.h"
coordinate::coordinate() :x(0), y(0) {}
coordinate::coordinate(float point_x, float point_y) {
	x = point_x;
	y = point_y;
	
}
float coordinate::get_x() { return x; }
float coordinate::get_y() { return y; }

istream& operator>>(istream& in, coordinate& point) {
	cout << "X:";
	in >> point.x;
	cout << "Y:";
	in >> point.y;
	return in;
};