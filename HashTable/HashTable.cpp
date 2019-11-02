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
   <�������ƣ�hash(const int tableSize,const string& key)
   <�������ܣ�����key�Ĺ�ϣֵ
   <����ֵ������һ��int����
**********************************/
int HashTable::hash(const string& key)const {
	int hashVal = 0;
	for (auto i : key)
		hashVal += i;
	return hashVal % tableSize;
}

/*********************************
    <�������ƣ�HashTable(const int& tableSize)
	<�������ܣ����캯��
*********************************/
HashTable::HashTable(const int& TableSize) {
	tableSize = TableSize;
	theList.reserve(TableSize);      //Ԥ���ռ�
	theList.resize(TableSize);       //�ı��С
}

/*********************************
	<�������ƣ�contains(const string& s)
	<�������ܣ�����s
	<����ֵ���ҵ�����bool�����򷵻�false
*********************************/
bool HashTable::contains(const Node& s) {
	auto pos = hash(s.key);
	auto it = find(theList[pos].begin(), theList[pos].end(), s);
	return (it == theList[pos].end()) ? false : true;
}

/*********************************
	<�������ƣ�insert(const string& s)
	<�������ܣ�����s
	<����ֵ���ɹ�����bool�����򷵻�false
*********************************/
bool HashTable::insert(const Node& s) {
	if (!contains(s)) {
		auto pos = hash(s.key);
		theList[pos].push_back(s);
		//����val��С��������
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
	<�������ƣ�remove(const string& s)
	<�������ܣ�ɾ��s
	<����ֵ���ɹ�����bool�����򷵻�false
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
	<�������ƣ�display()
	<�������ܣ����
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