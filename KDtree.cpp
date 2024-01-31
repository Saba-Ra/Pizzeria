#include "KDtree.h"
KDtree::KDtree() {
	root = NULL;
}
void KDtree::insert() {

}
void KDtree::Delete() {

}
void KDtree::pizzeria_in_region() {

}
void KDtree::nearest_pizzeria() {

}
void KDtree::nearest_branch() {

}
void KDtree::pizzeria_in_circle() {

}
void KDtree::pizzeria_sort(int begin, int end, int axis) {
	if (begin < end) {
		int middle = (end - begin) / 2;
		pizzeria_sort(begin, middle, axis);
		pizzeria_sort(middle + 1, end, axis);
		pizzeria_merge(begin, middle, end, axis);
	}
}
void KDtree::pizzeria_merge(int begin, int middle, int end, int axis) {
	int size1 = middle - begin + 1;
	int size2 = end - middle;

	treeNode* left = new treeNode[size1+1];
	treeNode* right = new treeNode[size2+1];
	left[size1].get_point().set_get_xy()[axis] = numeric_limits<double>::infinity();
	right[size2].get_point().set_get_xy()[axis] = numeric_limits<double>::infinity();

	for (int i = 0; i < size1; i++)
		left[i] = all_nodes[begin + i];
	for (int i = 0; i < size2; i++)
		right[i] = all_nodes[middle + 1 + i];

	for (int i = 0, j = 0, k=begin; k<=end; k++) {
		if (left[i].get_point().set_get_xy()[axis] < right[j].get_point().set_get_xy()[axis]) {
			all_nodes[k] = left[i];
			i++;
		}
		else {
			all_nodes[k] = right[j];
			j++;
		}
	}
}