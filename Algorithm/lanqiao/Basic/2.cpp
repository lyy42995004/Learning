#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    for (int i = 0; i < 32; ++i)
    {
        int n = 5;
        int x = i;
        string s;
        while (n--)
        {
            if (x % 2 == 1)
                s += '1';
            else
                s += '0';
            x /= 2;
        }
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    return 0;
}