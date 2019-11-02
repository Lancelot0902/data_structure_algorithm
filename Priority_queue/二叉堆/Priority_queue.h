#pragma once
/*********************
    <file_name:Priority_queue.h
	<author:Lancelot0902
	<date:2019.8.2
*********************/
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include <iostream>
#include <vector>
using namespace std;
class PriQueue {
public:
	PriQueue(int);
	PriQueue(vector<int>&);
	bool isFull();
	bool isEmpty();
	void insert(const int);
	const int deleteMin();
	void display();
	void makeEmpty();
	void destory();
	~PriQueue();
private:
	void bulidQueue();
	void percDown(int);
	vector<int> vec;
	int capcity;
	int size = 1;
};
#endif // !PRIORITY_QUEUE.H
