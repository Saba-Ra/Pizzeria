#pragma once
#include "chainNode.h"
class chain
{
	friend class hashTablePlus;
private:
	chainNode* head;
public:
	chain();
	void insert_front(chainNode*);
	void delete_node(const chainNode&);
};

