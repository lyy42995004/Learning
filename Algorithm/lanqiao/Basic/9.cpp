#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            for (int u = 0; u < 10; ++u)
            {
                if (n == 2 * i + 2 * j + u)
                    cout << i << j << u << j << i << endl;
            }
        }
    }
    for (int i = 1; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            for (int u = 0; u < 10; ++u)
            {
                if (n == 2 * i + 2 * j + 2 * u)
                    cout << i << j << u << u << j << i << endl;
            }
        }
    }
    return 0;
}