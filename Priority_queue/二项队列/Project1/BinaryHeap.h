/*********************
    <BinaryHeap.h
	<Lancelot0902
	<2019.8.8
*********************/
#ifndef BINARYHEAP_H
#define BINARYHEAP_H
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

template<typename T>
struct Node {
	T data;
	shared_ptr<Node<T>> left;
	shared_ptr<Node<T>> nextSibling;
	Node() = default;
	Node(const T& x):data(x),left(nullptr),nextSibling(nullptr){}
};

template<typename T>
class BinaryHeap {
public:
	BinaryHeap(const int);
	void insert(const T&);
	BinaryHeap<T> merge(BinaryHeap<T>);
	const T deleteMin();
private:
	shared_ptr<Node<T>> combine(shared_ptr<Node<T>>, shared_ptr<Node<T>>);
private:
	vector<shared_ptr<Node<T>>> vec;
};
#endif // !BINARYHEAP.H
