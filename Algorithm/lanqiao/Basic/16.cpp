#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isprime(int n)
{
    if (n == 2)
        return true;
    for (int i = 2; i < n; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void print(int a, vector<int> &v)
{
    int x = v[0], sum = 0, n = 0;
    while (sum != a)
    {
        if (a % x == 0 && (sum == 0 || a % (sum * x) == 0))
        {
            if (sum != 0)
                sum *= x;
            else
                sum = x;
            if (a == sum)
                cout << x << endl;
            else
                cout << x << '*';
        }
        else
            x = v[++n];
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    vector<int> v(b);
    for (int i = 2, j = 0; i <= b; ++i)
    {
        if (isprime(i))
            v[j++] = i;
    }
    while (a <= b)
    {
        if (int f = find(v.begin(), v.end(), a) != v.end())
            cout << a << '=' << a << endl;
        else
        {
            cout << a << '=';
            print(a, v);
        }
        a++;
    }
    return 0;
}