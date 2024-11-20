#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}