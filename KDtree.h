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
	treeNode* getRoot();
	void insert(string,string, coordinate, hashTable&);
	void Delete(coordinate, hashTable&);
	void pizzeria_in_region();
	double distance(coordinate,coordinate);
	void nearest_pizzeria(coordinate&, bool);
	treeNode* find_nearest( treeNode*,coordinate&,int);
	coordinate find_nearest(coordinate&, int);
	void nearest_branch(string, coordinate, hashTable&);
	void pizzeria_in_circle(const coordinate&, float);
	void pizzeria_traverse(coordinate, float, treeNode*, bool*);
	void pizzeria_sort(int, int, int, vector<treeNode*>&);
	void pizzeria_merge(int, int, int, int, vector<treeNode*>&);
	treeNode* buildTreeRecursive(int, int, int, vector <treeNode*>&);
	void buildTree(vector<treeNode*>&);
	~KDtree();
};

