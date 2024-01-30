#pragma once
#include <iostream>
using namespace std;
#include <string>
class coordinate
{
private:
	float x;
	float y;
public:
	coordinate();
	coordinate(float, float);
	float get_x();
	float get_y();
	friend istream& operator>>(istream&,coordinate&);
};
