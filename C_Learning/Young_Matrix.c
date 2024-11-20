#include <stdio.h>

struct point
{
    int x;
    int y;
};

struct point find_num(int arr[3][3], int a, int b, int n)
{
    struct point p = {-1, -1};
    int x = 0;
    int y = b - 1;
    while(x <= a - 1 && y >= 0)
    {   
        if(n < arr[x][y])
            y--;
        else if(n > arr[x][y])
            x++;
        else
        {
            p.x = x;
            p.y = y; 
            return p;
        }
    }
    return p;
}

int main()
{
    int arr[3][3] = {1,2,3,4,5,6,7,8,9};
    int x = 3, y = 3, n = 0;
    scanf("%d", &n);
    struct point ret = find_num(arr, x, y, n);
    printf("%d %d\n", ret.x, ret.y);
    return 0;
}