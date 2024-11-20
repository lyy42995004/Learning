#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector< vector<int> > vv(n);
    for (int i = 0; i < n; i++)
    {
        vv[i].resize(i + 1);
        vv[i][0] = vv[i][i] = 1;
        for (int j = 0; j < vv[i].size(); j++)
        {
            if (vv[i][j] != 1)
                vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < vv[i].size(); j++)
        {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}