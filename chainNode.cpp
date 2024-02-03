#include "chainNode.h"

chainNode::chainNode() {
	this->date.first = 0;
	this->next = nullptr;
}

chainNode::chainNode(pair<int, vector<string>> newData, chainNode* newNext) {
	this->date = newData;
	this->next = newNext;
}

chainNode::chainNode(const chainNode& secondNode) {
	this->date = secondNode.date;
	this->next = secondNode.next;
}

bool chainNode::operator==(const chainNode& second) const{
	return this->date.first == second.date.first && this->date.second == second.date.second && this->next == second.next;
}
