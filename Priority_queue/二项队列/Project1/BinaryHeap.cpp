/**********************
    <BinaryHeap.cpp
	<Lancelot0902
	<2019.8.8
**********************/
#include "BinaryHeap.h"


/**********************
	<BinaryHeap
	<构造函数
**********************/
template<typename T>
BinaryHeap<T>::BinaryHeap(const int size){
	vec.resize(size, nullptr);
}


/**********************
	<insert
	<插入新的节点
**********************/
template<typename T>
void BinaryHeap<T>::insert(const T& x){
	shared_ptr<Node<T>> newp(new Node<T>(x));
	for (int i = 0; i < vec.size(); ++i) {
		if (vec[i] == nullptr) {
			vec[i] = newp;
			break;
		}
		else
			newp = combine(newp, vec[i]);
	}
}


/**********************
	<merge
	<合并两个BinaryHeap
**********************/
template<typename T>
BinaryHeap<T> BinaryHeap<T>::merge(BinaryHeap<T> rhs){
	int maxSize = this->vec.size() >= rhs.vec.size() ? this->vec.size() : rhs.vec.size();
	shared_ptr<Node<T>> t1, t2, carry;
	for (int i = 0; i < maxSize(); ++i) {
		t1 = this->vec[i];
		t2 = rhs.vec[i];
		switch (!!t1 + 2 * !!t2 + 4 * !!carry) {
		  case 0:   //no trees
		  case 1:   //only t1
			  break;
		  case 2:   //only t2
			  this->vec[i] = t2;
			  rhs->vec[i] = nullptr;
			  break;
		  case 4:   //only carry
			  this->vec[i] = carry;
			  carry = nullptr;
			  break;
		  case 3:   //t1 + t2
			  carry = combine(t1, t2);
			  this->vec[i] = rhs.vec[i] = nullptr;
			  break;
		  case 5:   //t1 + carry
			  carry = combine(t1, carry);
			  this->vec[i] = nullptr;
			  break;
		  case 6:   //t2 + carry
			  carry = combine(t2, carry);
			  rhs->vec[i] = nullptr;
			  break;
		  case 7:   //t1 + t2 + carry
			  this->vec[i] = carry;
			  carry = combine(t1, t2);
			  rhs->vec[i] = nullptr;
			  break;
		}
	}
	return this;
}


/**********************
	<deleteMin
	<出队
**********************/
template<typename T>
const T BinaryHeap<T>::deleteMin(){
	int pos;
	const T min = vec[0]->data;
	shared_ptr<Node<T>> deleteMin;
	for (int i = 0; i != vec.size(); ++i) {
		if (vec[i]->data < min) {
			min = vec[i]->data;
			deleteMin = vec[i];
			pos = i;
		}
	}
	deleteMin = deleteMin->nextSibling;
	BinaryHeap deleteQueue(vec.size());
	for (int i = 0; i != deleteQueue->vec.size(); ++i) {
		deleteQueue->vec[i] = deleteMin;
		deleteMin = deleteMin->nextSibling;
		deleteQueue->vec[i]->nextSibling = nullptr;
	}
	this->vec[pos] = nullptr;
	merge(deleteQueue);
	return min;
}


/**********************
	<combine()
	<合并两个相同的Bk
**********************/
template<typename T>
shared_ptr<Node<T>> BinaryHeap<T>::combine(shared_ptr<Node<T>> h1, shared_ptr<Node<T>> h2){
	shared_ptr<Node<T>> p;
	if (h1->data > h2->data)
		return combine(h2, h1);
	else {
		p = h1->left;
		h1->left = h2;
		h2->nextSibling = p;
		return h1;
	}
}