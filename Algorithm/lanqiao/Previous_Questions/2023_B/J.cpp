#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 10;
vector<int> e[N];
int dep[N], top[N], son[N], fa[N], sz[N], diff[N];
map<pii, int> id;

void dfs1(int u, int v)
{
    dep[u] = dep[v] + 1, fa[u] = v, sz[u] = 1;
    for (auto x : e[u])
    {
        if (x == v)
            continue;
        dfs1(x, u);
        sz[u] += sz[x];
        if (sz[son[u]] < sz[x])
            son[u] = x;
    }
}

void dfs2(int u, int t)
{
    top[u] = t;
    if (!son[u])
        return;
    dfs2(son[u], t);
    for (auto x : e[u])
    {
        if (x == fa[u] || x == son[u])
            continue;
        dfs2(x, x);
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

void dfs3(int u, int v)
{
    for (auto x : e[u])
    {
        if (x == v)
            continue;
        dfs3(x, u);
        diff[u] += diff[x];
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
        id[{a, b}] = i;
        id[{b, a}] = i;
    }
    dfs1(1, 0);
    dfs2(1, 1);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        diff[a]++, diff[b]++;
        diff[lca(a, b)] -= 2;
    }
    dfs3(1, 0);
    int ans = -1;
    for (int i = 1; i <= n; ++i)
    {
        if (diff[i] == m)
        {
            int tmp = id[{i, fa[i]}];
            ans = max(tmp, ans);
        }
    }
    cout << ans << endl;
}

// 树上差分 + 最近公共祖先
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}

// typedef pair<int, int> pii;
// const int N = 1e5 + 10;
// vector<pii> e[N];
// int vis[N / 2];

// bool dfs(int end, int now, int last)
// {
//     if (now == end)
//         return true;
//     for (auto x : e[now])
//     {
//         int i = x.second, pos = x.first;
//         if (last == pos)
//             continue;
//         if (dfs(end, pos, now))
//         {
//             vis[i]++;
//             return true;
//         }
//     }
//     return false;
// }

// void solve()
// {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 1; i < n; ++i)
//     {
//         int a, b;
//         cin >> a >> b;
//         e[a].push_back({b, i});
//         e[b].push_back({a, i});
//     }
//     for (int i = 0; i < m; ++i)
//     {
//         int a, b;
//         cin >> a >> b;
//         dfs(b, a, -1);
//     }
//     int ans = -1;
//     for (int i = 1; i <= n; ++i)
//     {
//         if (vis[i] == m)
//             ans = i;
//     }
//     cout << ans << endl;
// }

// // DFS
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0), cout.tie(0);
//     solve();
//     return 0;
// }