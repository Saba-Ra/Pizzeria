#include "chain.h"

chain::chain() {
	head = nullptr;
}

void chain::insert_front(chainNode* newNode) {
	newNode->next = head;
	head = newNode;
}

void chain::delete_node(const chainNode& target) {
	chainNode* prev = nullptr;
	chainNode* curr = head;
	while (!(*curr == target)) {
		prev = curr;
		curr = curr->next;
	}
	prev->next = curr->next;
	delete curr;
}
