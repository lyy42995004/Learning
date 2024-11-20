#include <stdio.h>
#include <assert.h>

void* my_memcpy(void* dest, const void* src, size_t num)
{
    assert(dest && src);
    void* ret = dest;
    while(num--)
    {
        *(char*)dest = *(char*)src;
        dest = (char*)dest + 1;
        src = (char*)src + 1;
    }
    return ret;
}

int main()
{
    int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[10];
    my_memcpy(arr2, arr1, 40);
    for(int i = 0; i < 10;i++)
        printf("%d ", arr2[i]);
    return 0;
}