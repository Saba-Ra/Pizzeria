#pragma once
#include <iostream>
using namespace std;
#include <vector>

class chainNode
{
	friend class chain;
private:
	pair<int, vector<string>> data;
	chainNode* next;
public:
	chainNode();
	chainNode(pair<int, vector<string>>, chainNode*);
	chainNode(const chainNode&);
	bool operator==(const chainNode&) const ;
	int get_key()const;
	vector<string> get_value()const;
	chainNode* get_next()const;
};

