#include <iostream>
#include <vector>
using namespace std;
#include "AVLTree.h"

int main()
{
	const int N = 30;
	vector<int> v;
	v.reserve(N);
	// srand(time(0));

	for (size_t i = 0; i < N; i++)
	{
		v.push_back(rand());
		cout << v.back() << endl;
	}

	AVLTree<int, int> t;
	for (auto e : v)
	{
		t.Insert(make_pair(e, e));
		// 5cout << "Insert:" << e << "->" << t.IsBalance() << endl;
	}

	cout << t.IsBalance() << endl;

	return 0;
}