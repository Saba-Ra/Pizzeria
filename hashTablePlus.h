#pragma once
#include "chain.h"
class hashTablePlus
{
private:
	int size;
	vector<chain> table;
public:
	hashTablePlus();

	void insert(const chainNode&);

	int hash(const string&);
};

