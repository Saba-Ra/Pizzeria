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
	treeNode(string, const coordinate&, string, treeNode*, treeNode*);
	string get_name();
	string get_mainBranch();
	coordinate& get_point();
	treeNode*& set_get_left();
	treeNode*& set_get_right();
	bool operator==(treeNode&);
};

