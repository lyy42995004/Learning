#include <stdio.h>
#include <stdlib.h>

int main()
{
    int(*p)[5] = (int(*)[5])malloc(15 * sizeof(int));
    if (p == NULL)
    {
        perror("malloc");
        return 1;
    }
    int n = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            p[i][j] = n++;
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    free(p);
    p = NULL;
    return 0;
}