#include "chainNode.h"

chainNode::chainNode() {
	this->data.first = 0;
	this->next = nullptr;
}

chainNode::chainNode(pair<int, vector<string>> newData, chainNode* newNext) {
	this->data = newData;
	this->next = newNext;
}

chainNode::chainNode(const chainNode& secondNode) {
	this->data = secondNode.data;
	this->next = secondNode.next;
}

bool chainNode::operator==(const chainNode& second) const {
	return this->data.first == second.data.first && this->data.second == second.data.second && this->next == second.next;
}

int chainNode::get_key()const { return this->data.first; }

vector<string> chainNode::get_value()const { return this->data.second; }

chainNode* chainNode::get_next()const { return this->next; }