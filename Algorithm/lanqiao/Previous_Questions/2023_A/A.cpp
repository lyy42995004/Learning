#include <bits/stdc++.h>
using namespace std;

// 模拟
int main()
{
    int count = 0;
    for (int i = 1; i < 9; i += 2)
    {
        for (int j = pow(10, i); j < pow(10, i + 1); ++j)
        {
            int n = (i + 1) / 2;
            int s1 = 0, s2 = 0, tmp = j;
            for (int k = 0; k < i + 1; ++k)
            {
                if (k < n)
                    s1 += tmp % 10;
                else
                    s2 += tmp % 10;
                tmp /= 10;
            }
            if (s1 == s2)
                count++;
        }
    }
    cout << count << endl;
    return 0;
}