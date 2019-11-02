/**
 < Lancelot0902
 < Graph.cpp
**/
#include "Graph.h"
using namespace std;


Graph::Graph() {
	vec.resize(7);
	vec[0] = vector<int>{ 1,2,3 };
	vec[1] = vector<int>{ 0,3,4 };
	vec[2] = vector<int>{ 0,3,5 };
	vec[3] = vector<int>{ 0,1,2,4,5,6 };
	vec[4] = vector<int>{ 1,3,6 };
	vec[5] = vector<int>{ 2,3,6 };
	vec[6] = vector<int>{ 3,4,5 };
	am.resize(7);
	for (int i = 0; i != am.size(); ++i)
		am[i].resize(7, 0);
	am[0][1] = 2;
	am[0][2] = 4;
	am[0][3] = 1;
	am[1][0] = 2;
	am[1][3] = 3;
	am[1][4] = 10;
	am[2][0] = 4;
	am[2][3] = 2;
	am[2][5] = 5;
	am[3][0] = 1;
	am[3][1] = 3;
	am[3][2] = 2;
	am[3][4] = 7;
	am[3][5] = 8;
	am[3][6] = 4;
	am[4][1] = 10;
	am[4][3] = 7;
	am[4][6] = 6;
	am[5][2] = 5;
	am[5][3] = 8;
	am[5][6] = 1;
	am[6][3] = 4;
	am[6][4] = 6;
	am[6][5] = 1;
	dist.resize(7, infinity);
	known.resize(7, false);
	pv.resize(7);
}


void Graph::unWeight(int s) {   /*广度优先算法*/
	vector<int> Q;
	int i = s;
	Q.push_back(i);
	dist[2] = 0;
	while (Q.size() != 0) {
		i = *Q.begin();
		known[*Q.begin()] = true;
		Q.erase(Q.begin());
		for (int j = 0; j != vec[i].size(); ++j) {
			if (dist[vec[i][j]] == infinity) {  /*如果dist不等于极限值那么不用改变dist[w]的值*/
				dist[vec[i][j]] = dist[i] + 1;    /*因为如果改变dist[w]一定增大*/
				Q.push_back(vec[i][j]);
			}
		}
	}
}

void Graph::Dijkstra(int s) {
	dist[s] = 0;
	while (1) {
		if (count(known.begin(), known.end(), true) == known.size())
			break;
		else {
			int min = 0;
			/* find min of dist */
			for (int i = 0; i != known.size(); ++i) {
				if (known[i] == false)
					min = i;
			}
			for (int i = 0; i != dist.size(); ++i) {
				if (dist[min] > dist[i] && known[i] == false)
					min = i;
			}
			known[min] = true;
			/* each w for v */
			for (int i = 0; i != vec[min].size(); ++i) {
				if (known[vec[min][i]] != true)   /* update w */
					if (dist[vec[min][i]] > dist[min] + am[min][vec[min][i]])
						dist[vec[min][i]] = dist[min] + am[min][vec[min][i]];
			}
		}
	}
}


void Graph::Prim() {
	dist[0] = 0;
	while (1) {
		if (count(known.begin(), known.end(), true) == known.size())
			break;
		else {
			int min = 0;
			/* find min of dist */
			for (int i = 0; i != known.size(); ++i) {
				if (known[i] == false)
					min = i;
			}
			for (int i = 0; i != dist.size(); ++i) {
				if (dist[min] > dist[i] && known[i] == false)
					min = i;
			}
			known[min] = true;
			/* each w for v */
			for (int i = 0; i != vec[min].size(); ++i) {
				if (known[vec[min][i]] == false) {
					if (dist[vec[min][i]] > am[min][vec[min][i]]) {
						dist[vec[min][i]] = am[min][vec[min][i]];
						pv[vec[min][i]] = min;
					}
				}
			}
		}
	}
}


void Graph::Kruskal() {
	while (1) {
		if (count(known.begin(), known.end(), true) == known.size())
			break;
		else {
			if ((get<0>(msg.begin()->second) & get<1>(msg.begin()->second)) != true) {
				res.insert(*msg.begin());
				msg.erase(msg.begin());
				known[get<0>(msg.begin()->second)] = true;
				known[get<1>(msg.begin()->second)] = true;
			}
		}
	}
}


void Graph::display() {
	cout << "dist:";
	for (auto i : dist)
		cout << i << " ";
	cout << endl;
	cout << "pv:";
	for (auto i : pv)
		cout << i << " ";
	cout << endl;
}


int main(int argc, char** argv) {
	Graph p;
	//	p.unWeight(2);
	//	p.Dijkstra(0);
	p.Prim();
	p.display();
	system("pause");
	return 0;
}