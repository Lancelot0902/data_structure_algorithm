#include <iostream>
#include "Tree.h"
using namespace std;
BTree::BTree(const int x) {
	root = new TreeNode(x);
}

BTree::~BTree() {
	makeEmpty(root);
}

bool BTree::empty() {
	if (root == nullptr)
		return true;
	else
		return false;
}

bool BTree::find(int x) {
	if (look(x, root))
		return true;
	else
		return false;
}

int BTree::find_min() {
	auto p = look(-1, root);
	if (p != nullptr)
		return p->data;
	else
		return -1;
}

int BTree::find_max() {
	auto p = look(-2, root);
	if (p != nullptr)
		return p->data;
	else
		return -2;
}

void BTree::erase(int x) {
	auto p = look(x, root);
	if (p != nullptr) {   //no child
		if (p->left == nullptr && p->right == nullptr) {
			auto _father = find_father(x, p);
			_father->right = nullptr;
			delete(p);
			p = nullptr;
//			auto q = look(x, root);
			return;
		}
		if (p->right != nullptr || p->left != nullptr) {
			if (p->right != nullptr && p->left != nullptr) {   //two children
				auto min = look(-1, p->right);
				p->data = min->data;
				if (min->right != nullptr)
					p->right = min->right;
				delete(min);
				return;
			}
			if (p->right == nullptr) {  //one child
				auto father = find_father(x, root);
				father->right = p->left;
				delete(p);
				return;
			}
			if (p->left == nullptr) {
				auto father = find_father(x, root);
				father->left = p->right;
				delete(p);
				return;
			}
		}
	}
}

void BTree::insert(int x) {
	create(x, root);
}

void BTree::PreOrdPrint() {
	prePrint(root);
}


//工具函数定义在
void BTree::prePrint(TreeNode* p) {
	if (p != nullptr) {
		prePrint(p->left);
		cout << p->data << " ";
		prePrint(p->right);
	}
}

TreeNode* BTree::create(int x, TreeNode* p) {
	if (!p) {
		p = new TreeNode(x);
	}
	else {
		if (x < p->data)
			p->left = create(x, p->left);
		if (x > p->data)
			p->right = create(x, p->right);
	}
	return p;
}

TreeNode* BTree::look(int x, TreeNode* p) {
	if (x == -1) {
		if (p == nullptr)
			return nullptr;
		if (p->left == nullptr)
			return p;
		else
			return look(-1, p->left);
	}
	if (x == -2) {
		if (p == nullptr)
			return nullptr;
		if (p->right == nullptr)
			return p;
		else
			return look(-2, p->right);
	}
	if (p) {
		if (x < p->data)
			return look(x, p->left);
		if (x > p->data)
			return look(x, p->right);
		if (x == p->data)
			return p;
	}
}

TreeNode* BTree::find_father(int x, TreeNode* p) {
	if (p != nullptr) {
		if ((p->left!=nullptr&&p->left->data == x) || (p->right!=nullptr&&p->right->data == x))
			return p;
		if (x < p->data)
			return find_father(x, p->left);
		if (x > p->data)
			return find_father(x, p->right);
	}
	else
		return nullptr;
}

TreeNode* BTree::makeEmpty(TreeNode* p) {
	if (!p) {
		makeEmpty(p->left);
		makeEmpty(p->right);
		free(p);
	}
	return nullptr;
}

int main(int argc, char** argv) {
	BTree ob(3);
	ob.insert(2);
	ob.insert(4);
	ob.insert(5);
	ob.insert(8);
	ob.erase(8);
	if (ob.find(5))
		ob.PreOrdPrint();
	cout << endl;
	cout << ob.find_min() << endl;
	cout << ob.find_max() << endl;
	system("pause");
	return 0;
}