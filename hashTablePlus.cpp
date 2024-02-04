#include "hashTablePlus.h"
#include "neighborHood.h"
#include"KDtree.h"
#include <sstream>
hashTablePlus::hashTablePlus() :size(97), table(97){}

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
	chainNode* temp = table[index].first;
	while (temp != nullptr) {
		if (temp->get_key() == key) {
			return temp;
		}
		temp = temp->get_next();
	}
	throw runtime_error("\x1b[38;5;223m\t\t\t\t\tNo command found for the given input.\x1b[38;5;220m"); // Key not found
}


void hashTablePlus::Undo(int num_levels, int& current_level, neighborHood& regions, hashTable& table, KDtree& tree, hashTablePlus& commandsTable, list<pair<string, int>>& mostBranch) {
	if (current_level != 0 && num_levels < current_level) {
		for (int i = current_level; i > num_levels; i--) {
			try {
				chainNode* temp = search(i);
				stringstream cmd_ss(temp->get_value());
				string action, name, mainName, x1, y1;
				int x, y;
				cmd_ss >> action;
				if (action == "Add-N") {
					//delete region
					cmd_ss >> name;
					regions.Delete_region(name);
				}
				else if (action == "Add-P" || action == "Add-Br") {
					cmd_ss >> x1 >> y1;
					coordinate tmp;
					stringstream(x1) >> x;
					stringstream(y1) >> y;
					tmp.set_get_xy()[0] = x;
					tmp.set_get_xy()[1] = y;
					//delete mainBr or branch:
					if (action == "Add-P") {
						vector<treeNode*> all_nodes = tree.set_get_allNodes();
						auto it = std::find_if(all_nodes.begin(), all_nodes.end(), [&](treeNode* node) {
							return node->get_point() == tmp;
							});
						string deleteName = (*it)->get_name();
						all_nodes.erase(it);
						tree.buildTree(all_nodes);
						table.Delete(deleteName);
					}
					else if (action == "Add-Br") {
						tree.Delete(tmp, table, mostBranch, commandsTable, i, true, false);
					}
				}

				else if (action == "Del-Br") {
					cmd_ss >> mainName >> name >> x1 >> y1;
					coordinate tmp;
					stringstream(x1) >> x;
					stringstream(y1) >> y;
					tmp.set_get_xy()[0] = x;
					tmp.set_get_xy()[1] = y;
					tree.insert(mainName, name, tmp, table, commandsTable, i, false);
				}
				this->Delete(*temp);
			}
			catch (const exception& e) {}
		}
		current_level = num_levels;
	}
	else if (current_level != 0 && num_levels > current_level) {
		cout << "\x1b[38;5;223m\t\t\t\t\tAre you trying to go to a  time that doesn't exist?! 😀";
	}
	else {
		cout << "\x1b[38;5;223m\t\t\t\t\tNo commands yet!";
	}
}