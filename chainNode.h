#pragma once
#include <iostream>
using namespace std;
#include <vector>
class chainNode
{
	friend class chain;
private:
	pair<int, vector<string>> date;
	chainNode* next;
public:
	chainNode();
	chainNode(pair<int, vector<string>>, chainNode*);
	chainNode(const chainNode&);
	bool operator==(const chainNode&) const ;
};

