#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int a[N], n, m;

int find(int f)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (f > a[mid])
            left = mid + 1;
        else    
            right = mid;
    }
    return (f == a[left] ? left + 1 : -1);
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
    {
        int f;
        cin >> f;
        cout << find(f) << " ";
    }
    cout << endl;
    return 0;   
}