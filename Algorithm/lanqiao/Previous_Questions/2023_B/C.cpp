#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
    int n, ansMax = INT_MAX, ansMin = 0;
    cin >> n;
    while (n--)
    {
        int o, x;
        cin >> o >> x;
        ansMax = min(ansMax, o / x);
        ansMin = max(ansMin, o / (x + 1) + 1);
    }
    cout << ansMin << " " << ansMax << endl;
    return 0;
}