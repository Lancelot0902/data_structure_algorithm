/**************************
	 <¹é²¢ÅÅÐò
	 <Lancelot0902
	 <2019.8.11
**************************/

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& vec, vector<int>& tmp, int l, int mid, int r) {
	int posl = l;
	int posr = mid + 1;
	int i = l;
	while (posl <= mid && posr <= r) {
		if (vec[posl] <= vec[posr]) {
			tmp[i++] = vec[posl++];
		}
		if (vec[posl] > vec[posr]) {
			tmp[i++] = vec[posr++];
		}
	}
	while (posl <= mid)
		tmp[i++] = vec[posl++];
	while(posr <= r)
		tmp[i++] = vec[posr++];
	for (int j = l; j <= r; j++) {
		vec[j] = tmp[j];
	}
}

void mSort(vector<int>& vec, vector<int>& tmp, int l, int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		mSort(vec, tmp, l, mid);
		mSort(vec, tmp, mid + 1, r);
		merge(vec, tmp, l, mid, r);
	}
}

void mergeSort(vector<int>& vec) {
	if (!vec.empty()) {
		vector<int> tmp;
		tmp.resize(vec.size());
		mSort(vec, tmp, 0, vec.size() - 1);
	}
}