#pragma once
#include "coordinate.h"
#include<vector>
class hashNode
{
private:
	string name;
	coordinate point;
	vector<coordinate> branches;

public:
	hashNode();
	hashNode(string name, const coordinate&);
	hashNode(string name,const coordinate&, const vector<coordinate>&);
	string get_name();
	vector<coordinate> get_branches();
};

