#pragma once
#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <memory>
using namespace std;
struct TreeNode {   //节点声明
	TreeNode(int x) :data(x) {}
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
	int data = -1;
};
class BTree {   //树声明
public:
	BTree() = default;
	BTree(const int);
	~BTree();
	bool empty();
	bool find(int);
	int find_min();
	int find_max();
	void insert(int);
	void erase(int);
	void PreOrdPrint();
private:  //工具函数
	TreeNode* create(int, TreeNode*);
	TreeNode* makeEmpty(TreeNode*);
	TreeNode* look(int, TreeNode*);
	TreeNode* find_father(int, TreeNode*);
	void prePrint(TreeNode*);
private:
	TreeNode* root = nullptr;
};
#endif // !TREE_H