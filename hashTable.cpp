#include "hashTable.h"


hashTable::hashTable() : size(47), table(47) {}

void hashTable::insert(hashNode& Node) {
	int index = hash(Node.get_name());
	table[index].push_back(Node);
}

int hashTable::hash(const string& name) {
	int value = 0;
	for (auto i : name) {
		value += (int)i;
	}
	return value % size;
}
vector<coordinate>* hashTable::search(const string& name) {
	int index = hash(name);
	for (auto& mainBranch : table[index]) {
		if (mainBranch.get_name() == name) {
			return &mainBranch.get_branches();
		}
	}
	throw runtime_error("\x1b[38;5;223m\t\t\t\t\tNo branches found for the given name.\x1b[38;5;220m");
}
