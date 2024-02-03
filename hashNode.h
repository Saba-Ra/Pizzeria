#pragma once
#include "coordinate.h"
#include<vector>
class hashNode
{
private:
	string name;
	coordinate point;
	vector<pair<coordinate, string>> branches;

public:
	hashNode();
	hashNode(string name, const coordinate&);
	hashNode(string name,const coordinate&, const vector<pair<coordinate, string>>&);
	string get_name();
	vector<pair<coordinate, string>>& get_branches();
};

