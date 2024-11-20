#include <bits/stdc++.h>
using namespace std;

const int N = 63000;
bool a[N];

// 乒乓球
int main()
{
    int n = 0;
    char ch;
    while (cin >> ch && ch != 'E')
    {
        a[n] = ch == 'W' ? 1 : 0;
        n++;
    }
    if (n == 0)
        cout << "0:0\n\n0:0";
    int i = 0, x, y;
    while (i < n)
    {
        x = 0, y = 0;
        while (x < 11 && y < 11 && i < n)
        {
            a[i] == 1 ? x++ : y++;
            i++;
        }
        while (abs(x - y) < 2 && i < n)
        {
            a[i] == 1 ? x++ : y++;
            i++;
        }
        cout << x << ":" << y << endl;
    }
    if (abs(x - y) >= 2 && (x >= 11 || y >= 11))
        cout << "0:0\n";
    cout << endl;
    i = 0;
    while (i < n)
    {
        x = 0, y = 0;
        while (x < 21 && y < 21 && i < n)
        {
            a[i] == 1 ? x++ : y++;
            i++;
        }
        while (abs(x - y) < 2 && i < n)
        {
            a[i] == 1 ? x++ : y++;
            i++;
        }
        cout << x << ":" << y << endl;
    }
    if (abs(x - y) >= 2 && (x >= 21 || y >= 21))
        cout << "0:0\n";
    return 0;
}