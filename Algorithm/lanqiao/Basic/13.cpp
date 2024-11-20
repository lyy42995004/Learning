#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int i = 0;
    while (i != n)
    {
        cin >> arr[i++];
    }
    sort(arr, arr + n);
    i = 0;
    while (i != n)
    {
        cout << arr[i++] << " ";
    }
    cout << endl;
    return 0;
}