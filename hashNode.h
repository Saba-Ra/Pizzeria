#pragma once
#include "coordinate.h"
#include<vector>
class hashNode
{
private:
	string name;
	coordinate point;
	vector<coordinate> branches;
	hashNode* prev;
	hashNode* next;
public:
	hashNode();
	hashNode(string name,const coordinate&, const vector<coordinate>&, hashNode*, hashNode*);
};

