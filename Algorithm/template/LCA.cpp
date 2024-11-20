#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int N = 5e5 + 10;
vector<int> e[N];
int fa[N];  // 存父节点
int dep[N]; // 存深度
int son[N]; // 存重儿子
int sz[N];  // 存以当前节点为根子节点的个数
int top[N]; // 存当前节点所在重链顶点

// 得到fa[N], dep[N], sz[N], son[N]
void dfs1(int u, int father)
{
    fa[u] = father, dep[u] = dep[father] + 1, sz[u] = 1;
    for (auto v : e[u])
    {
        if (v == father)
            continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if (sz[son[u]] < sz[v])
            son[u] = v;
    }
}

// 得到top[N]
void dfs2(int u, int t)
{
    top[u] = t;
    if (!son[u])
        return;
    dfs2(son[u], t);
    for (auto v : e[u])
    {
        if (v == fa[u] || v == son[u])
            continue;
        dfs2(v, v);
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

void solve()
{
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs1(s, 0);
    dfs2(s, s);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
}

// 数链剖分
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}