#include <iostream>
using namespace std;

int main()
{
    int year;
    cin >> year;
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}