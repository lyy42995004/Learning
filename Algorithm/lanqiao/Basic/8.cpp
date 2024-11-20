#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cout << i << j << j << i << endl;
        }
    }
    return 0;
}