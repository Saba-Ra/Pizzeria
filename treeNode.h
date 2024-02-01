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
	string get_name();
	coordinate& get_point();
	treeNode*& set_get_left();
	treeNode*& set_get_right();
	bool operator==(treeNode&);
};

