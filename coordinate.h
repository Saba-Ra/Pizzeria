#pragma once
#include <iostream>
using namespace std;
#include <string>
class coordinate
{
private:
	float x_y[2];
public:
	coordinate();
	coordinate(float*);
	float* get_xy();
	friend istream& operator>>(istream&, coordinate&);
	coordinate& operator=(const coordinate&);
};
