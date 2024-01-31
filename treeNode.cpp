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
coordinate& treeNode::get_point() { return point; }

treeNode*& treeNode::set_get_left() { return left; }

treeNode*& treeNode::set_get_right() { return right; }

bool treeNode::operator==(treeNode& secondNode) { 
	return this->point == secondNode.point;
}
