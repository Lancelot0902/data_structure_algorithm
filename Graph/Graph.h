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
	void unWeight(int);           /* ����Ȩͼ�ĵ�Դ���· */
	void Dijkstra(int);           /* ���Ȩͼ�ĵ�Դ���· */
	void Prim();                  /* ������ͼ�е���С������ */
	void Kruskal();               /* ͬ�� */
	void display();
private:
	vector<vector<int>> vec;      /* �ڽӱ� */
	vector<vector<int>> am;       /* �ٽ���� */
	vector<int> dist;             /* ������S��ľ��� */
	vector<int> pv;               /* ���ڵ� */
	vector<bool> known;
	multimap<int, tuple<int, int>> msg;   /* ����߳�����Ϣ */
	multimap<int, tuple<int, int>> res;   /* �������ı߳� */
};
#endif // !GRAPH_H
