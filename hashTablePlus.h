#pragma once
#include "chain.h"
#include"hashTable.h"
#include <vector>
#include<list>

class KDtree;
class neighborHood;
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
	void Undo(int, int&, neighborHood& , hashTable& , KDtree&, hashTablePlus&, list<pair<string, int>>&);
};

