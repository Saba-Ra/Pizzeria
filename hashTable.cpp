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
vector<pair<coordinate, string>>* hashTable::search(const string& name) {
	int index = hash(name);
	for (auto& mainBranch : table[index]) {
		if (mainBranch.get_name() == name) {
			return &mainBranch.get_branches();
		}
	}
	throw runtime_error("\x1b[38;5;223m\t\t\t\t\tNo branches found for the given name.\x1b[38;5;220m");
}

void hashTable::Delete(const string& name)
{
	int index = hash(name);

	auto it = std::find_if(table[index].begin(), table[index].end(), [&](const hashNode& node) {
		return node.get_name() == name;
		});

	if (it != table[index].end()) {
		// Node found, erase it
		table[index].erase(it);
	}
	else {
		throw runtime_error("No entry found for the given name to delete.");
	}
}
