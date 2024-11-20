#include <bits/stdc++.h>
using namespace std;

// 找规律
int find(int n)
{
    return (n + 1) / 2 + n / 4;
}

int main()
{
    int l, r;
    cin >> l >> r;
    cout << find(r) - find(l - 1) << endl;
    return 0;
}