#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, a;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    cin >> a;
    vector<int>::iterator it = find(v.begin(), v.end(), a);
    if (it != v.end())
    {
        cout << (it - v.begin() + 1) << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}