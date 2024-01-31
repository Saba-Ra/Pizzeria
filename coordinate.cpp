#include "coordinate.h"
coordinate::coordinate() :x_y{ 0 } {}
coordinate::coordinate(float* point) {
	x_y[0] = point[0];
	x_y[1] = point[0];
}
float* coordinate::set_get_xy() { return x_y; }

istream& operator>>(istream& in, coordinate& point) {
	cout << "\t\t\t\t\tX:";
	in >> point.x_y[0];
	cout << "\t\t\t\t\tY:";
	in >> point.x_y[1];
	return in;
};

coordinate* coordinate::operator=(const coordinate& secondPoint) {
	x_y[0] = secondPoint.x_y[0];
	x_y[1] = secondPoint.x_y[1];
	return this;
}