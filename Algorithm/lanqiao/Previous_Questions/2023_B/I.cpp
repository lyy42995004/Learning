#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

// 图的储存
const int N = 1e5 + 10;
typedef pair<int, int> pii;
vector<pii> e[N];
int fa[N], son[N], top[N], sz[N], dep[N]; // LCA所需变量
int a[N];                                 // 记录要走的节点
int sum[N];                               // 记录到根节点的距离

void dfs1(int u, int father)
{
    dep[u] = dep[father] + 1, fa[u] = father, sz[u] = 1;
    for (auto v : e[u])
    {
        int i = v.first;
        if (i == father)
            continue;
        dfs1(i, u);
        sz[u] += sz[i];
        if (sz[son[u]] < sz[i])
            son[u] = i;
    }
}

void dfs2(int u, int t)
{
    top[u] = t;
    if (!son[u])
        return;
    dfs2(son[u], t);
    for (auto v : e[u])
    {
        int i = v.first;
        if (i == fa[u] || i == son[u])
            continue;
        dfs2(i, i);
    }
}

int lca(int u, int v)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        u = fa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}

void cal_sum(int u)
{
    for (auto v : e[u])
    {
        int i = v.first, w = v.second;
        if (i == fa[u])
            continue;
        sum[i] = sum[u] + w;
        cal_sum(i);
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v, t;
        cin >> u >> v >> t;
        e[u].push_back({v, t});
        e[v].push_back({u, t});
    }
    dfs1(1, 0);
    dfs2(1, 1);
    cal_sum(1);
    for (int i = 0; i < k; ++i)
        cin >> a[i];
    int s = 0;
    for (int i = 0; i < k - 1; ++i)
        s += sum[a[i]] + sum[a[i + 1]] - 2 * sum[lca(a[i], a[i + 1])];
    for (int i = 0; i < k; ++i)
    {
        int tmp = s;
        if (i == 0)
            tmp -= sum[a[i]] + sum[a[i + 1]] - 2 * sum[lca(a[i], a[i + 1])];
        else if (i == k - 1)
            tmp -= sum[a[i - 1]] + sum[a[i]] - 2 * sum[lca(a[i - 1], a[i])];
        else
        {
            tmp -= sum[a[i]] + sum[a[i + 1]] - 2 * sum[lca(a[i], a[i + 1])];
            tmp -= sum[a[i - 1]] + sum[a[i]] - 2 * sum[lca(a[i - 1], a[i])];
            tmp += sum[a[i - 1]] + sum[a[i + 1]] - 2 * sum[lca(a[i - 1], a[i + 1])];
        }
        cout << tmp << " ";
    }
    cout << endl;
}

// 树上前缀和 + 最近公共祖先
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}

// // 图的储存
// const int N = 1e5 + 10;
// typedef pair<int, int> pii;
// vector<pii> edge[N];

// map<pii, int> st; // 记录{x, y}的距离
// int a[N];         // 记录要走的节点

// bool dfs(int begin, int now, int end, int father, int sum)
// {
//     if (now == end)
//     {
//         st[{begin, end}] = sum;
//         st[{end, begin}] = sum;
//         return true;
//     }
//     for (int i = 0; i < edge[now].size(); i++)
//     {
//         int son = edge[now][i].first;
//         if (son == father)
//             continue;
//         int x = edge[now][i].second;
//         if (dfs(begin, son, end, now, sum + x))
//             return true;
//     }
//     return false;
// }

// void solve()
// {
//     int n, k, u, v, t; // u到v花费t
//     cin >> n >> k;
//     for (int i = 0; i < n - 1; ++i)
//     {
//         cin >> u >> v >> t;
//         edge[u].push_back({v, t});
//         edge[v].push_back({u, t});
//     }
//     for (int i = 0; i < k; i++)
//         cin >> a[i];
//     int sum = 0;
//     for (int i = 0; i < k - 1; i++) // O(k * n)
//     {
//         dfs(a[i], a[i], a[i + 1], -1, 0);
//         sum += st[{a[i], a[i + 1]}];
//     }
//     for (int i = 0; i < k; ++i)
//     {
//         int tmp = sum;
//         if (i == 0)
//             tmp -= st[{a[0], a[1]}];
//         else if (i == k - 1)
//             tmp -= st[{a[k - 2], a[k - 1]}];
//         else
//         {
//             dfs(a[i - 1], a[i - 1], a[i + 1], -1, 0);
//             tmp = tmp - st[{a[i - 1], a[i]}] - st[{a[i], a[i + 1]}] + st[{a[i - 1], a[i + 1]}];
//         }
//         cout << tmp << " ";
//     }
//     cout << endl;
// }

// // DFS暴力搜索 + 图的储存(只能过部分)
// signed main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0), cout.tie(0);
//     solve();
//     return 0;
// }