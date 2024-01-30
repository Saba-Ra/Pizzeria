#pragma once
#include"treeNode.h"
class KDtree
{
private:
	treeNode*root;
public:
	KDtree();
	void insert();
	void Delete();
	void pizzeria_in_region();
	void nearest_pizzeria();
	void nearest_branch();
	void pizzeria_in_circle();

};

