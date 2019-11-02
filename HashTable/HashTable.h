/****************************
	<author:Lancelot
	<flie_name:HashTable.h
	<creat_time:2019.7.22 9.16AM
****************************/
#pragma once
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//哈希表的节点定义，关键字和键值
struct Node {
	string key;
	int val;
	Node(const string& s,const int val):key(s),val(val){}
};
class HashTable {
public:
	HashTable(const int&);
	~HashTable() = default;
	bool contains(const Node&);
	bool insert(const Node&);
	bool remove(const Node&);
	void display();
private:
	int tableSize;
	vector<vector<Node>> theList;   //哈希表
	int hash(const string&)const;       //哈希函数        
};
#endif // !HASHTABLE_H