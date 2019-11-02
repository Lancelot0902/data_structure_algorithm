/**  2019.9.3      
 <  Lancelot0902
 <  Graph.h
**/
#pragma once
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <map>
#include <tuple>
#include <vector>
const int infinity = 999;
using namespace std;
class Graph {
public:
	Graph();
	void unWeight(int);           /* 求无权图的单源最短路 */
	void Dijkstra(int);           /* 求带权图的单源最短路 */
	void Prim();                  /* 求无向图中的最小生成树 */
	void Kruskal();               /* 同上 */
	void display();
private:
	vector<vector<int>> vec;      /* 邻接表 */
	vector<vector<int>> am;       /* 临界矩阵 */
	vector<int> dist;             /* 其余点距S点的距离 */
	vector<int> pv;               /* 父节点 */
	vector<bool> known;
	multimap<int, tuple<int, int>> msg;   /* 保存边长的信息 */
	multimap<int, tuple<int, int>> res;   /* 储存树的边长 */
};
#endif // !GRAPH_H
