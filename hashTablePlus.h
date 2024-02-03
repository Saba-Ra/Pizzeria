#pragma once
#include "chain.h"
#include <vector>

class hashTablePlus
{
private:
	int size;
	vector<chain> table;
public:
	hashTablePlus();
	void insert(const chainNode&);
	void Delete(const chainNode&);
	size_t multiplicationHash(int key)const;
	chainNode* search(int key);
};

