#include "hashTablePlus.h"

hashTablePlus::hashTablePlus() :size(97) {}

void hashTablePlus::insert(const chainNode& newNode) {
	size_t index = multiplicationHash(newNode.get_key());
	table[index].insert_front(newNode);
}

void hashTablePlus::Delete(const chainNode& target)
{ 
	size_t index = multiplicationHash(target.get_key());
	table[index].delete_node(target);
}

size_t hashTablePlus::multiplicationHash(int key)const {
	double constantA = 0.6180339887;
	double scaledKey = static_cast<double>(key) * constantA; //KA
	double fractionalPart = scaledKey - floor(scaledKey);  // KA mod 1
	return static_cast<size_t>(floor(size * fractionalPart)); // m(KA mod 1)
}

chainNode* hashTablePlus::search(int key) {
	size_t index = multiplicationHash(key);
	for (chainNode* it = table[index].last->get_next(); it != table[index].last; it++) {
		if (it->get_key() ==key ) {
			return it;
		}
	}
	throw runtime_error("\x1b[38;5;223m\t\t\t\t\tNo command found for the given input.\x1b[38;5;220m"); // Key not found
}

