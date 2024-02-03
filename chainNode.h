#pragma once
#include <iostream>
using namespace std;

class chainNode
{
	friend class chain;
private:
	pair<int, string> data;
	chainNode* next;
public:
	chainNode();
	chainNode(pair<int, string>, chainNode*);
	chainNode(const chainNode&);
	bool operator==(const chainNode&) const ;
	int get_key()const;
	string get_value()const;
	chainNode* get_next()const;
};

