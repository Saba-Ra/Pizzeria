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
	void insert(string, const coordinate&);
	void Delete(coordinate);
	void pizzeria_in_region();
<<<<<<< Updated upstream
	double distance(coordinate,coordinate);
	treeNode* nearest_pizzeria(coordinate&);
	treeNode* find_nearest( treeNode*,coordinate&,int);
=======
	coordinate nearest_pizzeria(coordinate&);
	coordinate find_nearest(coordinate&, int);
>>>>>>> Stashed changes
	void nearest_branch();
	void pizzeria_in_circle();
	void pizzeria_sort(int, int, int);
	void pizzeria_merge(int, int, int, int);
	treeNode* buildTreeRecursive(int, int, int);
	void buildTree();
};

