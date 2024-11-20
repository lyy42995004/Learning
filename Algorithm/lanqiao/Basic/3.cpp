#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    string s = "ZYXWVUTSRQPONMLKJIHGFEDCBABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int x = 25;
    for (int i = 0; i < n; ++i)
    {
        for (int j = x; j < x + m; ++j)
        {
            cout << s[j];
        }
        x--;
        cout << endl;
    }
    return 0;
}