/******************************
   <DisJointSet.h
   <Lancelot0902
   <2019.8.18
******************************/
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
struct Node{
	size_t pos;
	T data;
	Node():pos(0){}
};

template<typename T>
class DisJointSet {
public:
	DisJointSet(int);
	size_t Find(size_t,T);
	void Union(size_t,size_t);
private:
	vector<Node<T>> vec;
};