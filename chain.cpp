#include "chain.h"

chain::chain() : first(nullptr) {}

void chain::insert_front(const chainNode& newNode) {
    chainNode* newChainNode = new chainNode(newNode);
    if (first == nullptr) {
        first = newChainNode;
    }
    else {
        newChainNode->next = first;
        first = newChainNode;
    }
}

void chain::delete_node(const chainNode& nodeToDelete) {
    if (first == nullptr) {
        return;
    }

    chainNode* current = first;
    chainNode* previous = nullptr;

    while (current != nullptr) {
        if (current->data == nodeToDelete.data) {
            if (previous == nullptr) {
                first = current->next;
            }
            else {
                previous->next = current->next;
            }
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }
}
