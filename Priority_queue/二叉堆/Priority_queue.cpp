/********************************
	<file_name:Priority_queue.cpp
	<author:Lancelot0902
	<date:2019.8.2
*********************************/
#include <iostream>
#include <algorithm>
#include "Priority_queue.h"
using namespace std;


/**********************************
	<函数名称:PriQueue
	<函数参数:一个代表最小容量的int
	<函数功能:构造PriQueue对象
**********************************/
PriQueue::PriQueue(int _capcity) :capcity(_capcity)
{
	vec.reserve(capcity);
	vec.push_back(-1);
}

/*将一个原始的vector构造成二叉堆*/
PriQueue::PriQueue(vector<int>& vec){
	this->vec.reserve(vec.size() + 1);
	this->vec.push_back(-1);
	for (auto i : vec)
		this->vec.push_back(i);
	bulidQueue();
}


/**********************************
	<函数名称:isFull
	<函数参数:null
	<函数功能:判满
**********************************/
bool PriQueue::isFull()
{
	if (vec.size() == vec.capacity())
		return true;
	else
		return false;
}


/**********************************
	<函数名称:isEmpty
	<函数参数:null
	<函数功能:判空
**********************************/
bool PriQueue::isEmpty()
{
	if (vec.size() == 1)
		return true;
	else
		return false;
}


/**********************************
	<函数名称:insert
	<函数参数:模板类类型的T
	<函数功能:插入一个元素
**********************************/
void PriQueue::insert(const int val)
{
	if (isFull())
		throw runtime_error("no extra memory");
	vec.push_back(val);
	for (int i = vec.size() - 1; vec[i] < vec[i / 2]; i /= 2)
		std::swap(vec[i], vec[i / 2]);
	size++;
}


/**********************************
	<函数名称:deleteMin
	<函数参数:null
	<函数功能:出队
**********************************/
const int PriQueue::deleteMin()
{
	if (isEmpty()) {
		throw runtime_error("queue is empty");
		return vec[0];
	}
	int minElem = vec[1];
	int lastElem = vec[size - 1];
	int child = 0;
	vector<int>::iterator it = vec.end() - 1;
	int i;
	for (i = 1; i * 2 <= this->size - 1; i = child) {
		child = i * 2;
		if (child != size - 1 && vec[child + 1] < vec[child])
			child++;
		if (vec[child] < lastElem)
			vec[i] = vec[child];
		else
			break;
	}
	vec[i] = lastElem;
	vec.erase(it);
	return minElem;
}

void PriQueue::display()
{
	for (auto i : vec)
	{
		cout << i << " ";
	}

}


/**********************************
	<函数名称:makeEmpty
	<函数参数:null
	<函数功能:清空
**********************************/
void PriQueue::makeEmpty()
{
	vec.resize(1, -1);
}


/**********************************
	<函数名称:destory
	<函数参数:null
	<函数功能:删除表
**********************************/
void PriQueue::destory()
{
	vec.resize(0);
}

PriQueue::~PriQueue()
{
	this->destory();
}


/***********************
     <构建堆
***********************/
void PriQueue::bulidQueue(){
	for (int i = (vec.size()-1) / 2; i > 0; --i)
		percDown(i);
}

/**********************
     <下溢
**********************/
void PriQueue::percDown(int i){
	if (2 * i >= vec.size())
		return;
	else {
		if (2 * i + 1 >= vec.size()) {
			if (vec[2 * i] < vec[i]) {
				std::swap(vec[2 * i], vec[i]);
			}
			return;
		}
		if (vec[i] < vec[2 * i] && vec[i] < vec[2 * i + 1])
			return;
		else {
			if (vec[2 * i] < vec[2 * i + 1]) {
				std::swap(vec[i], vec[2 * i]);
				return percDown(2 * i);
			}
			else {
				std::swap(vec[i], vec[2 * i + 1]);
				return percDown(2 * i + 1);
			}
		}
	}
}


int main(int argc, char** argv) {
	
/*	p.insert(1);
	p.insert(3);
	p.insert(5);
	p.insert(8);
	p.insert(9);
	p.insert(4);
	p.deleteMin();  */
	vector<int> v{ 5,6,3,1,2,4 };
	PriQueue p(v);
	p.display();
	system("pause");
	return 0;
}