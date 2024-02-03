#include "chain.h"

chain::chain() {
	last = nullptr;
}

void chain::insert_front(const chainNode& Node) {
	chainNode* newNode = new chainNode(Node);
	last->next = newNode;
	last = newNode;
}

void chain::delete_node(const chainNode& target) {
	chainNode* prev = nullptr;
	chainNode* curr = last->next;
	while (!(*curr == target)) {
		prev = curr;
		curr = curr->next;
	}
	prev->next = curr->next;
	delete curr;
}
