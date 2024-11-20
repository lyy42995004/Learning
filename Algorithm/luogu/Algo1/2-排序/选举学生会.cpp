#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 10;
int a[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int b;
        cin >> b;
        a[b]++;
    }
    for (int i = 1; i <= n; ++i)
    {
        while (a[i]--)
            cout << i << " ";
    }
    cout << endl;
    return 0;   
}