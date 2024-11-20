#include <iostream>
using namespace std;

int main()
{
    int n, minx = 10000, maxx = -10000, sum = 0;
    cin >> n;
    while (n--)
    {
        int x; 
        cin >> x;
        minx = min(x, minx);
        maxx = max(x, maxx);
        sum += x; 
    }
    cout << maxx << endl << minx << endl << sum << endl;
    return 0;
}