/*************************
	<Ï£¶ûÅÅÐò
	<Lancelot0902
	<2019.8.10
*************************/

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void shellSort(vector<T>& vec) { 
	int i, j;
	for (int increment = vec.size() / 2; increment > 0; increment /= 2) {
		for (i = increment; i != vec.size(); ++i) {
			T tmp = vec[i];
			for (j = i; j >= increment && vec[j - increment] > tmp; j -= increment) {
				vec[j] = vec[j - increment];
			}
			vec[j] = tmp;
		}
	}
}