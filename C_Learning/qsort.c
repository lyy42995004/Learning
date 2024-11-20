#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//结构体

struct student
{
    char name[20];
    int age;
};

int struct_cmp_age(const void* p1, const void* p2)
{
    return ((struct student*)p1) -> age - ((struct student*)p2) -> age;
}

int struct_cmp_name(const void* p1, const void* p2)
{
    return strcmp(((struct student*)p1) -> name, ((struct student*)p2) -> name);
}

int main()
{
    struct student s[] = {{"ZhangSan",18},{"LiSi",20}};
    int sz = sizeof(s) / sizeof(s[0]);
    qsort(s, sz, sizeof(s[0]),struct_cmp_name);
    printf("%s %d\n%s %d\n", s[0].name, s[0].age, s[1].name, s[1].age);
    qsort(s, sz, sizeof(s[0]),struct_cmp_age);
    printf("%s %d\n%s %d\n", s[0].name, s[0].age, s[1].name, s[1].age);
    return 0;
}

//整形
/*
int int_cmp(const void* p1, const void* p2)
{
    return (*(int*)p1 - *(int*)p2);
}

int main()
{
    int arr[] = {2, 4, 6, 1, 3, 9, 10, 8, 7, 5};
    qsort(arr, (sizeof(arr) / sizeof(arr[0])), sizeof(int), int_cmp);
    for(int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
*/