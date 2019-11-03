/*********************
        <buctet_sort
	<Lancelot0902
	<2019.8.13
*********************/
#include <iostream>
#include <vector>
using namespace std;
vector<int> bucketSort(vector<int> vec) {
	int max = vec[1];
	for (auto i : vec) {
		if (i > max)
			max = i;
	}
	vector<int> res;
	res.resize(max);
	for (int i = 0; i != vec.size(); ++i) {
		res[vec[i]]++;
	}
	return res;
}
