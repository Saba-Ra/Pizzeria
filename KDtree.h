#pragma once
#include"treeNode.h"
#include <vector>
#include <limits>
#include"hashTable.h"
using namespace std;
class KDtree
{
private:
	treeNode* root;
	vector<treeNode*> all_nodes;
public:
	KDtree();
	void insert(string,string, coordinate, hashTable&);
	void Delete(coordinate);
	void pizzeria_in_region();
	double distance(coordinate,coordinate);
	treeNode* nearest_pizzeria(coordinate&);
	treeNode* find_nearest( treeNode*,coordinate&,int);
	coordinate find_nearest(coordinate&, int);
	void nearest_branch(string, const hashTable&);
	void pizzeria_in_circle();
	void pizzeria_sort(int, int, int);
	void pizzeria_merge(int, int, int, int);
	treeNode* buildTreeRecursive(int, int, int);
	void buildTree();
	~KDtree();
};

