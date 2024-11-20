#include <iostream>
#include <ctype.h>
using namespace std;

bool cmp(string &s1, string &s2)
{
    for (int i = 0; i < s1.size(); ++i)
    {
        s1[i] = tolower(s1[i]);
    }
    for (int i = 0; i < s2.size(); ++i)
    {
        s2[i] = tolower(s2[i]);
    }
    return s1 == s2;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.size() != s2.size())
        cout << 1 << endl;
    else if (s1 == s2)
        cout << 2 << endl;
    else if (cmp(s1, s2))
        cout << 3 << endl;
    else
        cout << 4 << endl;
    return 0;
}