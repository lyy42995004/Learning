#include <bits/stdc++.h>
using namespace std;

int n, score, ret;

void dfs()
{
    if (n == 30)
    {
        if (score == 70)
            ret++;
        return;
    }
    if (score == 100)
        return;
    if (score == 70)
        ret++;
    for (int i = 0; i < 2; ++i)
    {
        n++;
        if (i == 0)
        {
            int tmp = score;
            score = 0;
            dfs();
            score = tmp;
        }
        else
        {
            score += 10;
            dfs();
            score -= 10;
        }
        n--;
    }
}

// DFS
int main()
{
    dfs();
    cout << ret << endl;
    return 0;
}