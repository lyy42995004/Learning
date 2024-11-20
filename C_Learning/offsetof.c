#include <stdio.h>
#include <stddef.h>

#define OFFSETOF(s, m) ((size_t)&(((s*)0)->m))

struct s
{
    int a;
    char b[5];
    double c;
    char d[10];
};

int main()
{
    printf("a %ld\n", offsetof(struct s, a));
    printf("b %ld\n", offsetof(struct s, b));
    printf("c %ld\n", offsetof(struct s, c));
    printf("d %ld\n", offsetof(struct s, d));
    printf("a %ld\n", OFFSETOF(struct s, a));
    printf("b %ld\n", OFFSETOF(struct s, b));
    printf("c %ld\n", OFFSETOF(struct s, c));
    printf("d %ld\n", OFFSETOF(struct s, d));
    return 0;
}