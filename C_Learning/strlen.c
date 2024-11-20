#include <stdio.h>

//int my_strlen(char* s)
//{
//    int count = 0;
//    while(*s != '\0')
//    {
//        count++;
//        s++;
//    }
//    return count;
//}

int my_strlen(char* s)
{
    char* start = s;
    while(*s)
        s++;
    return s - start;
}

int main()
{
    int len = my_strlen("abcedf");
    printf("%d", len);
    return 0;
}