#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        //16进制->2进制->8进制
        string sixteen, bin, eight;
        cin >> sixteen;
        bin.reserve(sixteen.size() * 4);
        for (string::iterator it = sixteen.begin(); it != sixteen.end(); it++)
        {
            if (*it == '0')
                bin += "0000";
            else if (*it == '1')
                bin += "0001";
            else if (*it == '2')
                bin += "0010";
            else if (*it == '3')
                bin += "0011";
            else if (*it == '4')
                bin += "0100";
            else if (*it == '5')
                bin += "0101";
            else if (*it == '6')
                bin += "0110";
            else if (*it == '7')
                bin += "0111";
            else if (*it == '8')
                bin += "1000";
            else if (*it == '9')
                bin += "1001";
            else if (*it == 'A' || *it == 'a')
                bin += "1010";
            else if (*it == 'B' || *it == 'b')
                bin += "1011";
            else if (*it == 'C' || *it == 'c')
                bin += "1100";
            else if (*it == 'D' || *it == 'd')
                bin += "1101";
            else if (*it == 'E' || *it == 'e')
                bin += "1110";
            else if (*it == 'F' || *it == 'f')
                bin += "1111";
        }
        eight.reserve(bin.size() / 3 + 1);
        for (string::iterator it = bin.end() - 1; it >= bin.begin(); it -= 3)
        {
            if (it - bin.begin() > 2)
            {
                char tmp = (*(it - 2) - '0')*4 + (*(it - 1) - '0')*2 + *it;//优化
                eight += tmp;
            }
            else if (it - bin.begin() == 2)
            {
                char tmp = (*(it - 2) - '0')*4 + (*(it - 1) - '0')*2 + *it;
                if (tmp != '0')
                    eight += tmp;
            }
            else if (it - bin.begin() == 1)
            {
                char tmp = (*(it - 1) - '0')*2 + *it;
                if (tmp != '0')
                    eight += tmp;
            }
            else if (it - bin.begin() == 0)
            {
                if (*it == '1')
                    eight += "1";
            }
        }
        reverse(eight.begin(), eight.end());
        cout << eight << endl;
    }
    return 0;
}



// int main()
// {
//     int n;
//     cin >> n;
//     while (n--)
//     {
//         string sixteen, bin, eight;
//         cin >> sixteen;
//         bin.reserve(sixteen.size() * 4);
//         for (string::iterator it = sixteen.begin(); it != sixteen.end(); it++)
//         {
//             if (*it == '0')
//                 bin += "0000";
//             else if (*it == '1')
//                 bin += "0001";
//             else if (*it == '2')
//                 bin += "0010";
//             else if (*it == '3')
//                 bin += "0011";
//             else if (*it == '4')
//                 bin += "0100";
//             else if (*it == '5')
//                 bin += "0101";
//             else if (*it == '6')
//                 bin += "0110";
//             else if (*it == '7')
//                 bin += "0111";
//             else if (*it == '8')
//                 bin += "1000";
//             else if (*it == '9')
//                 bin += "1001";
//             else if (*it == 'A' || *it == 'a')
//                 bin += "1010";
//             else if (*it == 'B' || *it == 'b')
//                 bin += "1011";
//             else if (*it == 'C' || *it == 'c')
//                 bin += "1100";
//             else if (*it == 'D' || *it == 'd')
//                 bin += "1101";
//             else if (*it == 'E' || *it == 'e')
//                 bin += "1110";
//             else if (*it == 'F' || *it == 'f')
//                 bin += "1111";
//         }
//         eight.reserve(bin.size() / 3 + 1);
//         for (string::iterator it = bin.end() - 1; it >= bin.begin(); it -= 3)
//         {
//             if (it - bin.begin() >= 2)
//             {
//                 if (*(it - 2) == '1' && *(it - 1) == '1' && *it == '1')
//                     eight += "7";
//                 else if (*(it - 2) == '1' && *(it - 1) == '1' && *it == '0')
//                     eight += "6";
//                 else if (*(it - 2) == '1' && *(it - 1) == '0' && *it == '1')
//                     eight += "5";
//                 else if (*(it - 2) == '1' && *(it - 1) == '0' && *it == '0')
//                     eight += "4";
//                 else if (*(it - 2) == '0' && *(it - 1) == '1' && *it == '1')
//                     eight += "3";
//                 else if (*(it - 2) == '0' && *(it - 1) == '1' && *it == '0')
//                     eight += "2";
//                 else if (*(it - 2) == '0' && *(it - 1) == '0' && *it == '1')
//                     eight += "1";
//                 else if (*(it - 2) == '0' && *(it - 1) == '0' && *it == '0' && it - bin.begin() != 2)
//                     eight += "0";
//             }
//             else if (it - bin.begin() == 1)
//             {
//                 if (*(it - 1) == '1' && *it == '1')
//                     eight += "3";
//                 else if (*(it - 1) == '1' && *it == '0')
//                     eight += "2";
//                 else if (*(it - 1) == '0' && *it == '1')
//                     eight += "1";
//             }
//             else if (it - bin.begin() == 0)
//             {
//                 if (*it == '1')
//                     eight += "1";
//             }
//         }
//         reverse(eight.begin(), eight.end());
//         cout << eight << endl;
//     }
//     return 0;
// }