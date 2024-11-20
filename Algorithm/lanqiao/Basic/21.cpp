#include <iostream>
using namespace std;

void An(int x, int n)
{
    if (x == n + 1)
        return;
    if (x != 1)
    {
        if (x % 2 != 1)
            cout << '-';
        else
            cout << '+';
    }
    printf("sin(%d", x);
    An(x + 1, n);
    cout << ')';
}

void Sn(int x, int n)
{
    if (x == n + 1)
        return;
    if (x == 1)
        for (int i = 1; i < n; ++i)
            cout << '(';
    An(1, x);
    // printf("A(%d)", x);
    printf("+%d", n - x + 1);
    if (x != n)
        cout << ')';
    Sn(x + 1, n);
}

int main()
{
    int n;
    cin >> n;
    Sn(1, n);
    return 0;
}