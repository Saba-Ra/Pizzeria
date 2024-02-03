#include "hashTablePlus.h"

hashTablePlus::hashTablePlus():size(97){}

//void hashTablePlus::insert(chainNode& Node) {
//	int index = hash(Node.get_name());
//	table[index].push_back(Node);
//}

int hashTablePlus::hash(const string& name) {
	int value = 0;
	for (auto i : name) {
		value += (int)i;
	}
	return value % size;
}
