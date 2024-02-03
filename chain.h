#pragma once
#include "chainNode.h"
class chain
{
	friend class hashTablePlus;
private:
	chainNode* first;
public:
	chain();
	void insert_front(const chainNode&);
	void delete_node(const chainNode&);
};

