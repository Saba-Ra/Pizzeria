#include "hashNode.h"
hashNode::hashNode() {
	this->next = NULL;
	this->prev = NULL;

}
hashNode::hashNode(const coordinate&point, const vector<coordinate>&branches, hashNode*point_prev, hashNode*point_next) {
	this->point = point;
	this->branches = branches;
	this->prev = point_prev;
	this->next = point_next;
}

