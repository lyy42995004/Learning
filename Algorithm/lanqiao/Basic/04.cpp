#include <iostream>
using namespace std;

int main()
{
    int num1 = 1, num2 = 1;
    int n, fib;
    cin >> n;
    if (n <= 2)
    {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 3; i <= n; i++)
    {
        fib = (num1 + num2) % 10007;
        num1 = num2;
        num2 = fib;
    }
    cout << fib << endl;
    return 0;
}

// 运行超时
//  int fib(int n)
//  {
//      if (n == 1 || n == 2)
//          return 1;
//      else
//          return (fib(n - 1) + fib(n - 2)) % 10007;
//  }

// int main()
// {
//     int n;
//     cin >> n;
//     cout << fib(n) << endl;
//     return 0;
// }