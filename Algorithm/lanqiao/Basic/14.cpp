#include <iostream>
using namespace std;

int main()
{
    int t, h = 0, m = 0, s = 0;
    cin >> t;
    h = t / 3600;
    t %= 3600;
    m = t / 60;
    t %= 60;
    s = t;
    printf("%d:%d:%d\n", h, m, s);
    return 0;
}