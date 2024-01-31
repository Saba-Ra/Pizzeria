#include "coordinate.h"
coordinate::coordinate() :x_y{ 0 } {}
coordinate::coordinate(float* point) {
	x_y[0] = point[0];
	x_y[1] = point[0];
}
float* coordinate::get_xy() { return x_y; }

istream& operator>>(istream& in, coordinate& point) {
	cout << "X:";
	in >> point.x_y[0];
	cout << "Y:";
	in >> point.x_y[1];
	return in;
};

coordinate& coordinate::operator=(const coordinate& secondPoint) {
	x_y[0] = secondPoint.x_y[0];
	x_y[1] = secondPoint.x_y[1];
}