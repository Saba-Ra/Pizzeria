#include "hashNode.h"
hashNode::hashNode() :name("") {}
hashNode::hashNode(string name, const coordinate& point) {
	this->name = name;
	this->point = point;
}
hashNode::hashNode(string name, const coordinate& point, const vector<coordinate>& branches) {
	this->name = name;
	this->point = point;
	this->branches = branches;
}
string hashNode::get_name() { return this->name; }
vector<coordinate> hashNode::get_branches() { return this->branches; }