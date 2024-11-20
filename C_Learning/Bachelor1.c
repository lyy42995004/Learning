#include <stdio.h>

int main()
{
    int arr[9] = {1, 2, 3, 4, 5, 1, 2, 3, 4};
    int n = arr[0];
    for (int i = 1; i < 9; i++)
    {
        n ^= arr[i];
    }
    printf("%d", n);
    return 0;
}

// int main()
// {
//     int arr[9] = {1,2,3,4,5,1,2,3,4};
//     for(int i = 0; i < 9; i++)
//     {
//         int flag = 1;
//         for(int j = 0; j < 9; j++)
//         {
//             if(arr[i] == arr[j] && i != j)
//                 flag = 0;
//         }
//         if(flag)
//             printf("%d ", arr[i]);
//     }
//     return 0;
// }