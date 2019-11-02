#pragma once
#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
#include <memory>
using namespace std;
template<typename T> struct BSNode {
	T _val;
	shared_ptr<BSNode<T>> _parent;     //父结点
	shared_ptr<BSNode<T>> _left;       //左儿子
	shared_ptr<BSNode<T>> _right;      //右儿子
	int height;                        //高度
	BSNode() = default;
	BSNode(const T& val) :_val(val) {}
};
template<typename T> class BSTree {
public:
	BSTree() = default;
	BSTree(const T&);
	bool sch(const T&);
	shared_ptr<BSNode<T>> _sch(const T&, shared_ptr<BSNode<T>>);
	T schMin();
	shared_ptr<BSNode<T>> _schMin(shared_ptr<BSNode<T>>);
	T schMax();
	shared_ptr<BSNode<T>> _schMax(shared_ptr<BSNode<T>>);
	bool insert(const T&);
	shared_ptr<BSNode<T>> _insert(const T&, shared_ptr<BSNode<T>>, shared_ptr<BSNode<T>>);
	shared_ptr<BSNode<T>> insertAvl(const T& val, shared_ptr<BSNode<T>> p);
	bool erase(const T&);
	void print();
	void display(shared_ptr<BSNode<T>>);
	~BSTree() = default;
private:
	shared_ptr<BSNode<T>> root;
	shared_ptr<BSNode<T>> singleRotateWithLeft(shared_ptr<BSNode<T>> p);
	shared_ptr<BSNode<T>> doubleRotateWithRight(shared_ptr<BSNode<T>> p);
};
#endif // !BSTREE.H
