/***************************
	<LeftHeap.h
	<Lancelot0902
	<2019.8.6
***************************/
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

/***************************
    <�������Ľڵ㶨��
***************************/
template<typename T>
struct Node {
	T data;
	int npl;     //��·����
	shared_ptr<Node<T>> left;
	shared_ptr<Node<T>> right;
	Node(const T& x):data(x),left(nullptr),right(nullptr),npl(0){}
};


/**************************
    <LeftHeap����
**************************/
template<typename T>
class LeftHeap {
public:
	LeftHeap(const T&);
	bool isEmpty();
	shared_ptr<Node<T>> merge(shared_ptr<Node<T>>, shared_ptr<Node<T>>);
	void insert(const T&);
	const T deleteMin();
	void print();
public:
	shared_ptr<Node<T>> head;
private:
	void display(shared_ptr<Node<T>>);
	shared_ptr<Node<T>> Merge(shared_ptr<Node<T>>, shared_ptr<Node<T>>);
};