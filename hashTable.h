#pragma once
#include<iostream>
#include<string>
#include"hashNode.h"
#include"vector"
class hashTable
{
private:
	int size;
	vector<vector<hashNode>> table;
public:
	hashTable();

	void insert(hashNode&);

	int hash(const string&);

	vector<pair<coordinate, string>>* search(const string&);

	void Delete(const string&);
};
