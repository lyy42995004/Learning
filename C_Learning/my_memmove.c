#include <stdio.h>
#include <assert.h>

void *my_memmove(void *dest, const void *src, size_t num)
{
    assert(dest && src);
    void *ret = dest;
    if (dest < src)
    {
        while (num--)
        {
            *(char *)dest = *(char *)src;
            dest = (char *)dest + 1;
            src = (char *)src + 1;
        }
    }
    else
    {
        while (num--)
        {
            *((char *)dest + num) = *((char *)src + num);
        }
    }
    return ret;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    my_memmove(arr + 3, arr, 20);
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    return 0;
}