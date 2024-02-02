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
	float* set_get_xy();
	friend istream& operator>>(istream&, coordinate&);
	friend ostream& operator<<(ostream&, const coordinate&);
	coordinate* operator=(const coordinate&);
	bool operator==(const coordinate&) const;
};
