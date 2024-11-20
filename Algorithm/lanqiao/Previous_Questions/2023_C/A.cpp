#include <bits/stdc++.h>
using namespace std;

const int N = 1e9;

int main()
{
    int count = 0, sum = 0;
    for (int i = 1; i <= 20230408; ++i)
    {
        sum += i;
        if (sum > N)
        {
            sum %= N;
            count++;
        }
    }
    cout << sum << endl
         << count << endl;
    return 0;
}