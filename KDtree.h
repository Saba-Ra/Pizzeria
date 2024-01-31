#pragma once
#include"treeNode.h"
#include <vector>
#include <limits>
using namespace std;
class KDtree
{
private:
	treeNode* root;
	vector<treeNode> all_nodes;
public:
	KDtree();
	void insert();
	void Delete();
	void pizzeria_in_region();
	void nearest_pizzeria();
	void nearest_branch();
	void pizzeria_in_circle();
	void pizzeria_sort(int, int, int);
	void pizzeria_merge(int, int, int, int);
	treeNode* buildTree(const vector<treeNode>&, int);
};

