#include <iostream>
using namespace std;

int main()
{
    long long sum = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    printf("%lld\n", sum);
    return 0;
}