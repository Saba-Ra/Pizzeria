#pragma once

#include"vector"
#include"KDtree.h"
#include"windows.h"
class neighborHood
{
private:
	vector<pair<string, vector<coordinate>>> regions;

public:

	void insert(string, vector<coordinate>);
	void print();
	void search(string, KDtree&);
	void traverseTree(treeNode*, vector<coordinate>&,bool&);
	vector<coordinate> make_vec(coordinate, coordinate, coordinate, coordinate);
	bool isInsideRectangle(coordinate&, vector<coordinate>&);
};

