#include "KDtree.h"
#include"math.h"

KDtree::KDtree() {
	root = NULL;
}

treeNode* KDtree::getRoot() { return this->root; }


void KDtree::insert(string mainBranch, string name, coordinate point, hashTable& table) {
	treeNode* newNode = new treeNode(name, point, mainBranch, NULL, NULL);
	auto it = std::find_if(all_nodes.begin(), all_nodes.end(), [&](treeNode* node) {
		return node->get_point() == point;
		});
	if (it != all_nodes.end()) {
		cout << "\n\t\t\t\t\tThere is another pizzeria at this location!\n";
	}
	else {
		if (mainBranch != name) {
			try {
				table.search(mainBranch);
			}
			catch (exception error) {
				cout << "\n\t\t\t\t\tNo main branche matches the given name!" << endl;
				return;
			}
		}

		all_nodes.push_back(newNode);
		buildTree(all_nodes);

		if (mainBranch == name) { //which means this is a main branch and should be added to the hashtable
			hashNode newHashNode(name, point);
			table.insert(newHashNode);
		}
		coordinate newBranch(point.set_get_xy());
		table.search(mainBranch)->push_back(newBranch);
		cout << "\n\t\t\t\t\tYour pizzeria has been successfully added!\n";
	}
}

void KDtree::Delete(coordinate point, hashTable& table) {
	auto it = std::find_if(all_nodes.begin(), all_nodes.end(), [&](treeNode* node) {
		return node->get_point() == point;
		});
	if (it != all_nodes.end()) {
		if ((*it)->get_mainBranch() == (*it)->get_name()) {
			throw("You can not delete a main branch!");
		}
		else {
			string branchName = (*it)->get_mainBranch();
			vector<coordinate>* branches = table.search(branchName);
			auto it2 = std::find(branches->begin(), branches->end(), point);
			string deletedName = (*it)->get_name();
			branches->erase(it2);

			all_nodes.erase(it);
			buildTree(all_nodes);

			cout << "\n\t\t\t\t\t\"" << deletedName << "\" in location " << point << " clossed successfully";
		}
	}
	else {
		throw("There is no pizzeria at this location!");
	}
}

void KDtree::buildTree(vector<treeNode*>& all_tree_nodes) {
	root = buildTreeRecursive(0, all_tree_nodes.size() - 1, 0, all_tree_nodes);
}

treeNode* KDtree::buildTreeRecursive(int begin, int end, int depth, vector<treeNode*>& all_tree_nodes) {
	if (begin > end) {
		return nullptr;
	}

	int axis = depth % 2;

	// Sort points based on the current axis that is x or y
	this->KDtree::pizzeria_sort(begin, end, axis, all_tree_nodes);

	// Find the median point
	int medianIndex = (end - begin + 1) / 2;

	// Create a node and recursively build left and right subtrees
	treeNode* newNode;
	newNode = all_tree_nodes[begin + medianIndex];
	newNode->set_get_left() = buildTreeRecursive(begin, begin + medianIndex - 1, depth + 1, all_tree_nodes);
	newNode->set_get_right() = buildTreeRecursive(begin + medianIndex + 1, end, depth + 1, all_tree_nodes);

	return newNode;
}


double KDtree::distance(coordinate node, coordinate target) {
	double diff_x = node.set_get_xy()[0] - target.set_get_xy()[0];
	double diff_y = node.set_get_xy()[1] - target.set_get_xy()[1];
	return sqrt(diff_x * diff_x + diff_y * diff_y);
}

treeNode* KDtree::find_nearest(treeNode* current, coordinate& target, int depth) {
	if (current == NULL) return NULL;

	treeNode* nextBranch = target.set_get_xy()[depth % 2] < current->get_point().set_get_xy()[depth % 2] ? current->set_get_left() : current->set_get_right();
	treeNode* otherBranch = target.set_get_xy()[depth % 2] < current->get_point().set_get_xy()[depth % 2] ? current->set_get_right() : current->set_get_left();
	treeNode* best = find_nearest(nextBranch, target, depth + 1);

	//check the current and best distance
	double distance_curr = distance(current->get_point(), target);
	double distance_best = best != NULL ? distance(best->get_point(), target) : numeric_limits<double>::max();

	//update best if necessary
	if (distance_curr < distance_best)
		best = current;

	// Check the otherBranch if necessary
	if (abs(target.set_get_xy()[depth % 2] - current->get_point().set_get_xy()[depth % 2]) < distance_best) {
		treeNode* best_otherBranch = find_nearest(otherBranch, target, depth + 1);
		if (best_otherBranch != NULL) {
			double otherBranch_distance = distance(best_otherBranch->get_point(), target);
			if (otherBranch_distance < distance(best->get_point(), target)) {
				best = best_otherBranch;
			}
		}
	}

	return best;
}

void KDtree::nearest_pizzeria(coordinate& target, bool flag) {
	treeNode* foundNode = find_nearest(root, target, 0);

	if (flag)
		cout << "\n\x1b[38;5;223m\t\t\t\t\tNearest Pizzeria =>\n" << "\t\t\t\t\tName : " << foundNode->get_name() << endl << "\t\t\t\t\tLocation : " << foundNode->get_point() << "\x1b[38;5;208m";



	else
		cout << "\n\x1b[38;5;223m\t\t\t\t\tNearest Pizzeria =>\n" << "\t\t\t\t\tLocation : " << foundNode->get_point() << "\x1b[38;5;208m";

	return;
}

void KDtree::nearest_branch(string name, coordinate point, hashTable& table) {
	vector<coordinate> branches = *(table.search(name));
	vector<treeNode*> all_branch_nodes;
	for (auto i = branches.begin(); i != branches.end(); i++) {
		treeNode* newNode = new treeNode();
		newNode->get_point().set_get_xy()[0] = (*i).set_get_xy()[0];
		newNode->get_point().set_get_xy()[1] = (*i).set_get_xy()[1];
		all_branch_nodes.push_back(newNode);
	}

	KDtree mainBranchTree;
	mainBranchTree.buildTree(all_branch_nodes);
	bool flag = false;
	mainBranchTree.nearest_pizzeria(point, flag);

	//for (treeNode* node : all_branch_nodes) {
	//	delete node;
	//	node = nullptr;  // Nullify the pointer after deletion
	//}
	//all_branch_nodes.clear();  // Clear the vector after deleting all nodes

}

void KDtree::pizzeria_in_circle(const coordinate& A, float R) {
	bool atLeastOne = false;
	cout << "\n\t\t\t\t\t\x1b[38;5;223mPizzerias in this area:"<<endl;
	pizzeria_traverse(A, R, root, &atLeastOne);
	if (!atLeastOne) {
		cout << "\n\t\t\t\t\t\x1b[38;5;223mThere is no pizzeria in this area!";
	}
}

void KDtree::pizzeria_traverse(coordinate A, float R, treeNode* currentNode, bool* atLeastOne) {
	if (currentNode == nullptr)
		return;
	if (distance(A, currentNode->get_point()) <= R) {
		cout << "\n\t\t\t\t\x1b[38;5;223m Name : " << currentNode->get_name() << "\tLocation : " << currentNode->get_point() << endl;
		*atLeastOne = true;
	}
	pizzeria_traverse(A, R, currentNode->set_get_left(), atLeastOne);
	pizzeria_traverse(A, R, currentNode->set_get_right(), atLeastOne);
}

void KDtree::pizzeria_sort(int begin, int end, int axis, vector<treeNode*>& all_tree_nodes) {
	if (begin < end) {
		int middle = (end - begin) / 2;
		pizzeria_sort(begin, begin + middle, axis, all_tree_nodes);
		pizzeria_sort(begin + middle + 1, end, axis, all_tree_nodes);
		pizzeria_merge(begin, begin + middle, end, axis, all_tree_nodes);
	}
}

void KDtree::pizzeria_merge(int begin, int middle, int end, int axis, vector<treeNode*>& all_tree_nodes) {
	int size1 = middle - begin + 1;
	int size2 = end - middle;

	treeNode* left = new treeNode[size1 + 1];
	treeNode* right = new treeNode[size2 + 1];

	left[size1].get_point().set_get_xy()[axis] = numeric_limits<double>::infinity();
	right[size2].get_point().set_get_xy()[axis] = numeric_limits<double>::infinity();

	for (int i = 0; i < size1; i++)
		left[i] = *all_tree_nodes[begin + i];
	for (int j = 0; j < size2; j++)
		right[j] = *all_tree_nodes[middle + 1 + j];

	for (int i = 0, j = 0, k = begin; k <= end; k++) {
		if (left[i].get_point().set_get_xy()[axis] < right[j].get_point().set_get_xy()[axis]) {
			all_tree_nodes[k] = &left[i];
			i++;
		}
		else {
			all_tree_nodes[k] = &right[j];
			j++;
		}
	}
}

KDtree::~KDtree() {
	for (treeNode* node : all_nodes) {
		delete node;
	}
}
