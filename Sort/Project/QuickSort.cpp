/*******************
   <quick_sort
   <Lancelot0902
   <2019.8.11
*******************/
#include <iostream>
#include <vector>
using namespace std;

int media3(vector<int>& vec, int l, int r) {
	int mid = (l + r) / 2;
	if (vec[l] > vec[mid])
		std::swap(vec[l], vec[mid]);
	if (vec[l] > vec[r])
		std::swap(vec[l], vec[r]);
	if (vec[mid] > vec[r])
		std::swap(vec[mid], vec[r]);
	std::swap(vec[mid], vec[r - 1]);
	return vec[r - 1];
}

void qSort(vector<int>& vec, int l, int r) {
	if (l < r) {
		int pivot = media3(vec, l, r);
		int i = l;
		int j = r - 1;
		while (1) {
			while (i < j && vec[++i] < pivot);
			while (i < j && vec[--j] > pivot);
			if (i < j)
				std::swap(vec[i], vec[j]);
			else
				break;
		}
		std::swap(vec[i], vec[r - 1]);
		qSort(vec, l, i - 1);
		qSort(vec, i + 1, r);
	}
}
