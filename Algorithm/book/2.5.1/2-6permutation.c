#include <stdio.h>

// i在123 - 329之间
int main()
{
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            if (i == j)
                continue;
            for (int k = 1; k < 10; k++)
            {
                if (j == k || i == k)
                    continue;
                int x = i * 100 + j * 10 + k;
                int y = 2 * x;
                int z = 3 * x;
                int a = y / 100;
                int b = y / 10 % 10;
                int c = y % 10;
                int d = z / 100;
                int e = z / 10 % 10;
                int f = z % 10;
                if (a + b + c + d + e + f + i + j + k != 45)
                    continue;
                else if (a == 0 || b == 0 || c == 0 || d == 0 || e == 0 || f == 0)
                    continue;
                else if (a == i || a == j || a == k || a == b || a == c || a == d || a == e || a == f)
                    continue;
                else if (b == i || b == j || b == k || b == c || b == d || b == e || b == f)
                    continue;
                else if (c == i || c == j || c == k || c == d || c == e || c == f)
                    continue;
                else if (d == i || d == j || d == k || d == e || d == f)
                    continue;
                else if (e == i || e == j || e == k || e == f)
                    continue;
                else if (f == i || f == j || f == k)
                    continue;
                else
                    printf("%d %d %d\n", x, y, z);
            }
        }
    }
    return 0;
}