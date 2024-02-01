#include "hashNode.h"
hashNode::hashNode() {
	this->name = "";
	this->next = NULL;
	this->prev = NULL;
}
hashNode::hashNode(string name,const coordinate&point, const vector<coordinate>&branches, hashNode*point_prev, hashNode*point_next) {
	this->name = name;
	this->point = point;
	this->branches = branches;
	this->prev = point_prev;
	this->next = point_next;
}
string hashNode::get_name() { return this->name; }
vector<coordinate> hashNode::get_branches() { return this->branches; }