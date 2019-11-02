/*********************
   <DisJointSet.cpp
   <Lancelot0902
   <2019.8.18
**********************/
#include "DisJointSet.h"

/*********************
   <DisJointSet()
   <constructor
**********************/
template<typename T>
DisJointSet<T>::DisJointSet(int n){
	vec.resize(n);
	for (int i = 0; i != n; i++)
		vec[0] = Node();
}


/*********************
   <Find()
   <member function
   <一般策略
**********************/
template<typename T>
size_t DisJointSet<T>::Find(size_t x,T _data){
	if (vec[x].pos == 0)
		return x;
	else
		return Find(vec[x].pos, _data);
}

/*********************
   <路径压缩
**********************/
template<typename T>
size_t DisJointSet<T>::Find(size_t x, T _data) {
	if (vec[x].pos == 0)
		return x;
	else
		return vec[x].pos = Find(vec[x].pos, _data);
}


/*********************
   <Union()
   <member function
   <一般策略
**********************/
template<typename T>
void DisJointSet<T>::Union(size_t a,size_t b){
	vec[b].pos = a;
}

/*********************
   <大小合并
**********************/
template<typename T>
void DisJointSet<T>::Union(size_t a, size_t b) {
	vec[b].pos = a;
}