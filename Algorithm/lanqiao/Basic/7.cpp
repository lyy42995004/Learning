#include <iostream>
using namespace std;

int main()
{
    for (int i = 100; i < 1000; ++i)
    {
        int a = i % 10;
        int b = i / 10 % 10;
        int c = i / 100;
        if (i == a * a * a + b * b * b + c * c * c)
            cout << i << endl;
    }
    return 0;
}