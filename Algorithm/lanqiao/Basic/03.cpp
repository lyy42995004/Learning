#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double pi = 4 * atan(1);
    int r;
    cin >> r;
    double s = pi * r * r;
    printf("%.7f", s);
    return 0;
}