#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "RBTree.h"
#include "map.h"
#include "set.h"

void test_set()
{
	chan::set<int> s;
	s.insert(4);
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(2);
	s.insert(0);
	s.insert(10);
	s.insert(5);

	chan::set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	it = s.begin();

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_map()
{
	chan::map<string, string> dict;
	dict.insert(make_pair("sort", "排序"));
	dict.insert(make_pair("sort", "xx"));
	dict.insert(make_pair("left", "左边"));
	dict.insert(make_pair("right", "右边"));

	chan::map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

	string arr[] = {"苹果", "菠萝", "西瓜", "菠萝", "西瓜", "菠萝", "西瓜", "西瓜", "菠萝", "西瓜", "苹果", "西瓜", "苹果"};
	chan::map<string, int> countMap;
	for (auto &e : arr)
	{
		countMap[e]++;
	}

	for (auto &kv : countMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;
}

int main()
{
	test_set();
	test_map();

	return 0;
}