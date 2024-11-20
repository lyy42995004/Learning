#include <stdio.h>

int main()
{
    int arr[1000][1000] = {0};
    int n;
    arr[1][1] = arr[2][1] = arr[2][2] = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if(i > 2)
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}