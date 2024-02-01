#pragma once
#include<iostream>
#include<string>
#include"treeNode.h"
#include"vector"
class hashTable
{
private:
	int size;
	vector<vector<treeNode>> table;
public:
    hashTable(int);

    void insert(treeNode&);
    
    int hash(const string&);

    int search(const string& name);


};

