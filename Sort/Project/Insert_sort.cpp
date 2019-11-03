/***************************
	  <insert_sort
	  <Lancelot0902
	  <2019.8.10
***************************/
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void insertSort(vector<T>& vec) {
	int i, j;
	for (i = 1; i != vec.size(); ++i) {
		T tmp = vec[i];
		for (j = i; j > 0 && vec[j - 1] > tmp; --j) {
			vec[j] = vec[j - 1];
		}
		vec[j] = tmp;
	}
}
