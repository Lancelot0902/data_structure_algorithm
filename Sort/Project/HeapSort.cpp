/***************************
	  <¶ÑÅÅÐò
	  <Lancelot0902
	  <2019.8.11
***************************/
#include <iostream>
#include <vector>
using namespace std;

vector<int> vec{ -1,5,6,3,1,2,4 };

void percDown(int);
void bulidHeap() {
	for (int i = (vec.size() - 1) / 2; i > 0; --i)
		percDown(i);
}

void percDown(int i) {
	if (2 * i >= vec.size())
		return;
	else {
		if (2 * i + 1 >= vec.size()) {
			if (vec[2 * i] > vec[i]) {
				std::swap(vec[2 * i], vec[i]);
			}
			return;
		}
		if (vec[i] > vec[2 * i] && vec[i] > vec[2 * i + 1])
			return;
		else {
			if (vec[2 * i] > vec[2 * i + 1]) {
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


void heapSort() {
	bulidHeap();
	int size = vec.size();
	for (int i = 0; i != vec.size() - 1 - 1; ++i) {
		int maxElem = vec[1];
		int lastElem = vec[size - 1];
		int child = 0;
		int j;
		for (j = 1; j * 2 <= size - 1; j = child) {
			child = j * 2;
			if (child != size - 1 && vec[child + 1] > vec[child])
				child++;
			if (vec[child] > lastElem)
				vec[j] = vec[child];
			else
				break;
		}
		vec[j] = lastElem;
		vec[size - 1] = maxElem;
		size--;
		cout << endl;
	}
}