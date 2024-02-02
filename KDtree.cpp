#include "KDtree.h"
#include"math.h"

KDtree::KDtree() {
	root = NULL;
}


void KDtree::insert(string mainBranch, string name, coordinate point, hashTable& table) {
	treeNode* newNode = new treeNode(name, point, mainBranch, NULL, NULL);
	auto it = std::find_if(all_nodes.begin(), all_nodes.end(), [&](treeNode* node) {
		return node->get_point() == point;
		});
	if (it != all_nodes.end()) {
		cout << "There is another pizzeria at this location!\n";
	}
	else {
		all_nodes.push_back(newNode);
		buildTree();
		if (mainBranch == "") { //which means this is a main branch and should be added to the hashtable
			hashNode newHashNode(name, point);
			table.insert(newHashNode);
		}
		else { //this is a branch 
			//float x_y = { point.set_get_xy()[0], point.set_get_xy()[1] };
			coordinate newBranch();
			try {
				/*table.search(name).push_back(newBranch);*/
			}
			catch (char* error) {
				cout << "No main branche matches the given name." << endl;
			}
		}
		cout << "Your pizzeria has been successfully added!\n";
	}
}


void KDtree::buildTree() {
	root = buildTreeRecursive(0, all_nodes.size() - 1, 0);
}

treeNode* KDtree::buildTreeRecursive(int begin, int end, int depth) {
	if (begin > end) {
		return nullptr;
	}

	int axis = depth % 2;

	// Sort points based on the current axis that is x or y
	this->KDtree::pizzeria_sort(begin, end, axis);

	// Find the median point
	int medianIndex = (end - begin + 1) / 2;

	// Create a node and recursively build left and right subtrees
	treeNode* newNode;
	newNode = all_nodes[begin + medianIndex];
	newNode->set_get_left() = buildTreeRecursive(begin, begin + medianIndex - 1, depth + 1);
	newNode->set_get_right() = buildTreeRecursive(begin + medianIndex + 1, end, depth + 1);

	return newNode;
}

void KDtree::Delete(coordinate point) {
	auto it = std::find_if(all_nodes.begin(), all_nodes.end(), [&](treeNode* node) {
		return node->get_point() == point;
		});

	if (it != all_nodes.end()) {
		all_nodes.erase(it);
		buildTree();
	}
	//else {
	//	cout << " ";
	//}
}

void KDtree::pizzeria_in_region() {

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
	if (distance_curr < distance_best)best = current;

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

void KDtree::nearest_pizzeria(coordinate& target) {
	treeNode*foundNode= find_nearest(root, target, 0);
	cout <<"\n\x1b[38;5;223m\t\t\t\t\tNearest Pizzeria =>\n"<<"\t\t\t\t\tName : " << foundNode->get_name()<<endl<<"\t\t\t\t\tX : "<<foundNode->get_point().set_get_xy()[0]<<endl<<"\t\t\t\t\tY : "<< foundNode->get_point().set_get_xy()[0]<<"\x1b[38;5;208m";
	return;
}

void KDtree::nearest_branch(string name, const hashTable& table) {

}

void KDtree::pizzeria_in_circle() {

}

void KDtree::pizzeria_sort(int begin, int end, int axis) {
	if (begin < end) {
		int middle = (end - begin) / 2;
		pizzeria_sort(begin, begin + middle, axis);
		pizzeria_sort(begin + middle + 1, end, axis);
		pizzeria_merge(begin, begin + middle, end, axis);
	}
}

void KDtree::pizzeria_merge(int begin, int middle, int end, int axis) {
	int size1 = middle - begin + 1;
	int size2 = end - middle;

	treeNode* left = new treeNode[size1 + 1];
	treeNode* right = new treeNode[size2 + 1];

	left[size1].get_point().set_get_xy()[axis] = numeric_limits<double>::infinity();
	right[size2].get_point().set_get_xy()[axis] = numeric_limits<double>::infinity();

	for (int i = 0; i < size1; i++)
		left[i] = *all_nodes[begin + i];
	for (int i = 0; i < size2; i++)
		right[i] = *all_nodes[middle + 1 + i];

	for (int i = 0, j = 0, k = begin; k <= end; k++) {
		if (left[i].get_point().set_get_xy()[axis] < right[j].get_point().set_get_xy()[axis]) {
			all_nodes[k] = &left[i];
			i++;
		}
		else {
			all_nodes[k] = &right[j];
			j++;
		}
	}
}

KDtree::~KDtree() {
	for (treeNode* node : all_nodes) {
		delete node;
	}
}
