#pragma once
#include"treeNode.h"
#include <vector>
#include <limits>
#include <list>
#include"hashTable.h"
#include "hashTablePlus.h"
using namespace std;
class KDtree
{
private:
	treeNode* root;
	vector<treeNode*> all_nodes;
public:
	KDtree();
	treeNode* getRoot();
	void insert(string, string, coordinate, hashTable&, hashTablePlus&, int, bool);
	void Delete(coordinate, hashTable&, list<pair<string, int>>&, hashTablePlus&, int, bool, bool);
	void pizzeria_in_region();
	double distance(coordinate, coordinate);
	void nearest_pizzeria(coordinate&, bool);
	treeNode* find_nearest(treeNode*, coordinate&, int);
	coordinate find_nearest(coordinate&, int);
	void nearest_branch(string, coordinate, hashTable&);
	void pizzeria_in_circle(const coordinate&, float);
	void pizzeria_traverse(coordinate, float, treeNode*, bool*);
	void pizzeria_sort(int, int, int, vector<treeNode*>&);
	void pizzeria_merge(int, int, int, int, vector<treeNode*>&);
	treeNode* buildTreeRecursive(int, int, int, vector <treeNode*>&);
	void buildTree(vector<treeNode*>&);
	vector<treeNode*>& set_get_allNodes();
	~KDtree();
};

