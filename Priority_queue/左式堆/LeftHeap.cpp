/***************************
	<LeftHeap.cpp
	<Lancelot0902
	<2019.8.6
***************************/
#include "LeftHeap.h"

/***************************
	<LeftHeap()
	<构造左式堆
	<一个保存数据的vector
***************************/
template<typename T>
LeftHeap<T>::LeftHeap(const T& x){
	head = shared_ptr<Node<T>>(new Node<T>(x));
}


/***************************
	<isEmpty()
	<检查是否为空
***************************/
template<typename T>
bool LeftHeap<T>::isEmpty(){
	if (head == nullptr)
		return true;
	return false;
}


/***************************
	<merge()
	<合并两个左式堆
	<两个左式堆h1,h2
***************************/
template<typename T>
shared_ptr<Node<T>> LeftHeap<T>::merge(shared_ptr<Node<T>> h1, shared_ptr<Node<T>> h2){
	if (h1 == nullptr)
		return h2;
	if (h2 == nullptr)
		return h1;
	if (h1->data < h2->data)
		return Merge(h1, h2);
	if (h1->data > h2->data)
		return Merge(h2, h1);
}


/***************************
	<insert()
	<插入x
	<利用单节点的合并操作
***************************/
template<typename T>
void LeftHeap<T>::insert(const T& x){
	shared_ptr<Node<T>> newp(new Node<T>(x));
	head = merge(head, newp);
}


/***************************
	<deleteMin()
	<左式堆的出队
	<合并根的left和right
***************************/
template<typename T>
const T LeftHeap<T>::deleteMin(){
	const T res = head->data;
	head = merge(head->left, head->right);
	return res;
}

template<typename T>
void LeftHeap<T>::print(){
	display(head);
}

template<typename T>
void LeftHeap<T>::display(shared_ptr<Node<T>> p){
	if (p != nullptr) {
		display(p->left);
		cout << p->data << " ";
		display(p->right);
	}
}

/***************************
	<Merge()
	<实际执行合并的函数
***************************/
template<typename T>
shared_ptr<Node<T>> LeftHeap<T>::Merge(shared_ptr<Node<T>> h1, shared_ptr<Node<T>> h2) {
	if (h1->left == nullptr)
		h1->left = h2;
	else {
		h1->right = merge(h1->right, h2);
		if (h1->left->npl < h1->right->npl) {    //左儿子的npl至少与右儿子的npl一样大
			auto index = h1->left;
			h1->left = h1->right;
			h1->right = index;
		}
		h1->npl = h1->right->npl + 1;
	}
	return h1;
}

/***************
    <test
***************/
int main(int argc, char** argv) {
	LeftHeap<int> p(3);
	LeftHeap<int> q(21);
	p.insert(5);
	p.insert(9);
	p.insert(6);
	q.insert(11);
	q.insert(15);
	q.insert(4);
	p.merge(p.head, q.head);
//	p.deleteMin();
	p.print();
//	cout << endl;
//	q.print();
	system("pause");
}