#include "treeNode.h"
treeNode::treeNode(){
	this->name = "";
	this->mainBranch = "";
	this->left = NULL;
	this->right = NULL;
}
treeNode::treeNode(string name,const coordinate& node_point, string node_mainBranch, treeNode* left_child, treeNode* right_child) {
	this->name = name;
	this->point = node_point;
	this->mainBranch = node_mainBranch;
	this->left = left_child;
	this->right = right_child;
}
