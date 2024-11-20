#include <stdio.h>

int main()
{
    FILE *pf1 = fopen("./SelfLearning/Learn_C/data.txt", "r");
    if (!pf1)
    {
        perror("fopen -> data.txt");
        return 0;
    }
    FILE *pf2 = fopen("./SelfLearning/Learn_C/data_copy.txt", "w");
    if (!pf2)
    {
        fclose(pf1);
        pf1 = NULL;
        perror("fopen -> data_copy.txt");
        return 1;
    }
    int ch;
    while ((ch = fgetc(pf1)) != EOF)
    {
        fputc(ch, pf2);
    }
    fclose(pf1);
    fclose(pf2);
    pf1 = pf2 = NULL;
    return 0;
}