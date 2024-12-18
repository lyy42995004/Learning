#include <stdio.h>
#include <math.h>

int main()
{
    int n = 0;
    double pi = acos(-1.0);
    scanf("%d", &n);
    printf("%lf %lf\n", sin(n * pi / 180.0), cos(n * pi / 180.0));
    return 0;
}