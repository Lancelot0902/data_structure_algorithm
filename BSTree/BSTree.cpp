#include <iostream>
#include "BSTree.h"
using namespace std;

/**************************
	<函数名称:BSTree
	<函数功能:有参构造
**************************/
template<typename T>
BSTree<T>::BSTree(const T& val) {
	this->root = shared_ptr<BSNode<T>>(new BSNode<T>(val));
}

/**************************
	<函数名称:sch
	<函数功能:查找
**************************/
template<typename T>      //非递归版本
bool BSTree<T>::sch(const T& val) {
	auto it = root;
	while (it != nullptr) {
		if (it->_val > val) {
			it = it->_left;
			break;
		}
		if (it->_val < val) {
			it = it->_right;
			break;
		}
		if (it->_val == val)
			return true;
	}
	return false;
}
template<typename T>       //递归版本
shared_ptr<BSNode<T>> BSTree<T>::_sch(const T& val, shared_ptr<BSNode<T>> p) {
	if (p != nullptr) {
		if (p->_val > val)
			return _sch(val, p->_left);
		if (p->_val < val)
			return _sch(val, p->_right);
		if (p->_val == val)
			return p;
	}
	else
		return nullptr;
}

/**************************
	<函数名称:schMin
	<函数功能:查找最小
**************************/
template<typename T>      //非递归
T BSTree<T>::schMin() {
	/*if (this->root != nullptr) {
		auto it = this->root;
		while (it->_left != nullptr) {
			it = it->_left;
		}
		return it->_val;
	}*/
	auto res = _schMin(this->root);
	return res->_val;
}
template<typename T>     //递归
shared_ptr<BSNode<T>> BSTree<T>::_schMin(shared_ptr<BSNode<T>> p) {
	if (p->_left != nullptr) {
		return _schMin(p->_left);
	}
	return p;
}

/**************************
	<函数名称:schMax
	<函数功能:查找最大
**************************/
template<typename T>      //非递归
T BSTree<T>::schMax() {
	/*if (this->root != nullptr) {
		auto it = this->root;
		while (it->_right != nullptr) {
			it = it->_right;
		}
		return it->_val;
	}*/
	auto res = _schMax(this->root);
	return res->_val;
}
template<typename T>       //递归
shared_ptr<BSNode<T>> BSTree<T>::_schMax(shared_ptr<BSNode<T>> p) {
	if (p->_right != nullptr) {
		return _schMax(p->_right);
	}
	return p;
}

/**************************
	<函数名称:insert
	<函数功能:插入
**************************/
template<typename T>      //非递归
bool BSTree<T>::insert(const T& val) {
	/*if (this->root != nullptr && sch(val) != true) {
		auto it = this->root;
		shared_ptr<BSNode<T>> parent = this->root;
		while (it != nullptr) {
			if (it->_val > val) {
				parent = it;
				it = it->_left;
				break;
			}
			if (it->_val < val) {
				parent = it;
				it = it->_right;
				break;
			}
		}
		it = shared_ptr<BSNode<T>>(new BSNode<T>(val));
		it->_parent = parent;
		if (it->_val < parent->_val)
			parent->_left = it;
		if (it->_val > parent->_val)
			parent->_right = it;
		return true;
	}
	else
		return false;*/
	auto res=_insert(val, this->root, this->root);
	if (res != nullptr)
		return true;
	else
		return false;
}
template<typename T>  //递归
shared_ptr<BSNode<T>> BSTree<T>::_insert(const T& val, shared_ptr<BSNode<T>> p,shared_ptr<BSNode<T>> parent) {
	if (p != nullptr) {
		parent = p;
		if (p->_val < val)
			p->_right = _insert(val, p->_right, parent);
		if (p->_val > val)
			p->_left= _insert(val, p->_left, p);
	}
	else {
		p = shared_ptr<BSNode<T>>(new BSNode<T>(val));
		p->_parent = parent;
	}
	return p;
}
template<typename T>     //带平衡条件的AVL树的查找
shared_ptr<BSNode<T>> BSTree<T>::insertAvl(const T& val, shared_ptr<BSNode<T>> p) {
	if (p == nullptr) {
		p = shared_ptr<BSNode<T>>(new BSNode<T>(val));
		p->height = 0;
		p->_left = p->_right = nullptr;
	}
	if (val<p->_val) {
		p->_left = insertAvl(val, p->_left);
		if (p->_left->height - p->_right->right == 2) {
			if (val < p->_left->val)
				p = singleRotateWithLeft(p)
			else
				p = doubleRotateWithRight(p);
		}
	}
	if (val > p->_val) {
		p->_right = insertAvl(val, p->_right);
		if (p->_right->height - p->_left->height == 2) {
			if (val < p->_left->val)
				p = doubleRotateWithLeft(p);
			else
				p = singleRotateWithRight(p);
		}
	}
	p->height = (p->_left->height > p->_right->height) ? p->_left->height + 1 : p->_right->height + 1;
	return p;
}

/**************************
	<函数名称:erase
	<函数功能:删除
**************************/
template<typename T>      //非递归
bool BSTree<T>::erase(const T& val) {
	auto it = _sch(val, this->root);
	if (it != nullptr) {
		shared_ptr<BSNode<T>> parent(it->_parent);
		if (it->_left == nullptr && it->_right == nullptr) {
			it->_parent == nullptr;
			if (it->_val < parent->_val)
				parent->_left = nullptr;
			if (it->_val > parent->_val)
				parent->_right = nullptr;
			return true;
		}
		else if (it->_left != nullptr && it->_right != nullptr) {
			auto min(_schMin(this->root));
			it->_val = min->_val;
			if (min->_right != nullptr) {
				min->_parent->_left = min->_right;
				min->_right->_parent = min->_parent;
				min->_parent == nullptr;
			}
			else {
				auto parent = min->_parent;
				min->_parent = nullptr;
				parent->_left = nullptr;
			}
			return true;
		}
		else {
			if (it->_left != nullptr) {
				if (it->_val > it->_parent->_val) {
					it->_parent->_right = it->_left;
					it->_left->_parent = it->_parent;
					it->_parent = nullptr;
				}
				if (it->_val < it->_parent->_val) {
					it->_parent->_left = it->_left;
					it->_left->_parent = it->_parent;
					it->_parent = nullptr;
				}
			}
			if (it->_right != nullptr) {
				if (it->_val > it->_parent->_val) {
					it->_parent->_right = it->_right;
					it->_right->_parent = it->_parent;
					it->_parent = nullptr;
				}
				if (it->_val < it->_parent->_val) {
					it->_parent->_left = it->_right;
					it->_right->_parent = it->_parent;
					it->_parent = nullptr;
				}
			}
			return true;
		}
	}
}

template<typename T>
void BSTree<T>::print() {
	display(this->root);
}

template<typename T>
void BSTree<T>::display(shared_ptr<BSNode<T>> p) {
	if (p != nullptr) {
		display(p->_left);
		cout << p->_val << "";
		display(p->_right);
	}
}
template<typename T>
shared_ptr<BSNode<T>> BSTree<T>::singleRotateWithLeft(shared_ptr<BSNode<T>> p)
{
	shared_ptr k1 = p->_left;
	p->_left = k1->_right;
	k1->right = p;
	p->height = max(p->_left->height, p->_right->height) + 1;
	k1->height = max(k1->_left->height, p->height);
	return k1;
}

template<typename T>
shared_ptr<BSNode<T>> BSTree<T>::doubleRotateWithRight(shared_ptr<BSNode<T>> p)
{
	p->left = singleRotateWithRight(p->left);
	return singleRotateWithLeft(p);
}


int main(int argc, char** argv) {
	BSTree<int> widget(6);
	widget.insert(2);
	widget.insert(8);
	widget.insert(1);
	widget.insert(5);
	widget.insert(3);
	widget.insert(4);
	widget.erase(2);
	widget.print();
//	cout << widget.schMax() << widget.schMin() << endl;
	system("pause");
	return 0;
}