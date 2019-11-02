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
	<��������:PriQueue
	<��������:һ��������С������int
	<��������:����PriQueue����
**********************************/
PriQueue::PriQueue(int _capcity) :capcity(_capcity)
{
	vec.reserve(capcity);
	vec.push_back(-1);
}

/*��һ��ԭʼ��vector����ɶ����*/
PriQueue::PriQueue(vector<int>& vec){
	this->vec.reserve(vec.size() + 1);
	this->vec.push_back(-1);
	for (auto i : vec)
		this->vec.push_back(i);
	bulidQueue();
}


/**********************************
	<��������:isFull
	<��������:null
	<��������:����
**********************************/
bool PriQueue::isFull()
{
	if (vec.size() == vec.capacity())
		return true;
	else
		return false;
}


/**********************************
	<��������:isEmpty
	<��������:null
	<��������:�п�
**********************************/
bool PriQueue::isEmpty()
{
	if (vec.size() == 1)
		return true;
	else
		return false;
}


/**********************************
	<��������:insert
	<��������:ģ�������͵�T
	<��������:����һ��Ԫ��
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
	<��������:deleteMin
	<��������:null
	<��������:����
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
	<��������:makeEmpty
	<��������:null
	<��������:���
**********************************/
void PriQueue::makeEmpty()
{
	vec.resize(1, -1);
}


/**********************************
	<��������:destory
	<��������:null
	<��������:ɾ����
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
     <������
***********************/
void PriQueue::bulidQueue(){
	for (int i = (vec.size()-1) / 2; i > 0; --i)
		percDown(i);
}

/**********************
     <����
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