/**********************************
   <author:Lancelot
   <file_name:HashTable.cpp
   <creat_time:2019.7.22 9.31AM
**********************************/

#include <iostream>
#include <algorithm>
#include "HashTable.h"
using namespace std;

/**********************************
   <函数名称：hash(const int tableSize,const string& key)
   <函数功能：返回key的哈希值
   <返回值：返回一个int整数
**********************************/
int HashTable::hash(const string& key)const {
	int hashVal = 0;
	for (auto i : key)
		hashVal += i;
	return hashVal % tableSize;
}

/*********************************
    <函数名称：HashTable(const int& tableSize)
	<函数功能：构造函数
*********************************/
HashTable::HashTable(const int& TableSize) {
	tableSize = TableSize;
	theList.reserve(TableSize);      //预留空间
	theList.resize(TableSize);       //改变大小
}

/*********************************
	<函数名称：contains(const string& s)
	<函数功能：查找s
	<返回值：找到返回bool，否则返回false
*********************************/
bool HashTable::contains(const Node& s) {
	auto pos = hash(s.key);
	auto it = find(theList[pos].begin(), theList[pos].end(), s);
	return (it == theList[pos].end()) ? false : true;
}

/*********************************
	<函数名称：insert(const string& s)
	<函数功能：查找s
	<返回值：成功返回bool，否则返回false
*********************************/
bool HashTable::insert(const Node& s) {
	if (!contains(s)) {
		auto pos = hash(s.key);
		theList[pos].push_back(s);
		//按照val从小到大排序
		sort(theList[pos].begin(), theList[pos].end(),
			[](const Node& lhs, const Node& rhs)->bool {return lhs.val < rhs.val; });
		if (contains(s))
			return true;
		else
			return false;
	}
}
bool operator==(const Node& lhs, const Node& rhs) {
	return lhs.key == rhs.key;
}
/*********************************
	<函数名称：remove(const string& s)
	<函数功能：删除s
	<返回值：成功返回bool，否则返回false
*********************************/
bool HashTable::remove(const Node& s) {
	auto pos = hash(s.key);
	auto it = find(theList[pos].begin(), theList[pos].end(), s);
	if (it != theList[pos].end()) {
		theList[pos].erase(it);
		if (contains(s))
			return false;
		else
			return true;
	}
	else
		throw runtime_error("no exsit");
}

/*********************************
	<函数名称：display()
	<函数功能：输出
*********************************/
void HashTable::display() {
	for (int i = 0; i != tableSize; ++i) {
		for (auto it : theList[i])
			cout << it.key << "->";
		cout << endl;
	}
}


int main(int argc, char** argv) {
	HashTable ob(10);
	Node a("abc", 1);
	ob.insert(a);
	ob.insert(Node("abd",2));
	if (ob.contains(a))
		cout << "yes" << endl;
	ob.remove(a);
	ob.display();
	system("pause");
	return 0;
}