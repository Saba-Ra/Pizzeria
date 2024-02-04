#include "hashNode.h"
hashNode::hashNode() :name("") {}
hashNode::hashNode(string name, const coordinate& point) {
	this->name = name;
	this->point = point;
}
hashNode::hashNode(string name, const coordinate& point, const vector <pair<coordinate, string>>& branches) {
	this->name = name;
	this->point = point;
	this->branches = branches;
}
string hashNode::get_name()const { return this->name; }
vector<pair<coordinate, string>>& hashNode::get_branches() { return this->branches; }