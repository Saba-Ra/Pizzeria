#pragma once
#include "coordinate.h"
class treeNode
{
private:
	string name;
	coordinate point;
	string mainBranch;
	treeNode* left;
	treeNode* right;
public:
	treeNode();
	treeNode(string name, const coordinate& node_point, string node_mainBranch, treeNode* left_child, treeNode* right_child);
	coordinate get_point();
};

