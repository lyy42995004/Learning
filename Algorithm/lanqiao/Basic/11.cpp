#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    unsigned int n = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
            n = n * 16 + s[i] - '0';
        else
            n = n * 16 + s[i] - 'A' + 10;
    }
    cout << n << endl;
    return 0;
}