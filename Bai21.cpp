#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18;
const int LOG = 20;

struct dsu
{
    vector<int> par;
    vector<int> sz;
    void init(int n)
    {
        par.resize(n + 1);
        sz.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
            sz[i] = 1;
        }
    }
    int find(int a)
    {
        if (a == par[a])
            return a;
        return par[a] = find(par[a]);
    }
    bool make(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return true;
        if (sz[a] < sz[b])
            swap(a, b);
        sz[a] += sz[b];
        par[b] = a;
        return false;
    }
};

struct Edge
{
    int u, v, w, id;
    bool is_mst = false;
};

vector<pair<int, int>> adj[100005];
int up[100005][LOG], max_e[100005][LOG], depth[100005];

void dfs(int u, int p, int w, int d)
{
    depth[u] = d;
    up[u][0] = p;
    max_e[u][0] = w;
    for (int i = 1; i < LOG; i++)
    {
        up[u][i] = up[up[u][i - 1]][i - 1];
        max_e[u][i] = max(max_e[u][i - 1], max_e[up[u][i - 1]][i - 1]);
    }
    for (auto &edge : adj[u])
    {
        if (edge.first != p)
            dfs(edge.first, u, edge.second, d + 1);
    }
}

int getmax(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    int res = 0;
    for (int i = LOG - 1; i >= 0; i--)
    {
        if (depth[u] - (1 << i) >= depth[v])
        {
            res = max(res, max_e[u][i]);
            u = up[u][i];
        }
    }
    if (u == v)
        return res;
    for (int i = LOG - 1; i >= 0; i--)
    {
        if (up[u][i] != up[v][i])
        {
            res = max({res, max_e[u][i], max_e[v][i]});
            u = up[u][i];
            v = up[v][i];
        }
    }
    return max({res, max_e[u][0], max_e[v][0]});
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].id = i;
    }

    sort(edges.begin(), edges.end(), [](Edge a, Edge b)
         { return a.w < b.w; });

    dsu tree;
    tree.init(n);
    long long mst_weight = 0;
    int edges_used = 0;

    for (int i = 0; i < m; i++)
    {
        if (tree.find(edges[i].u) != tree.find(edges[i].v))
        {
            tree.make(edges[i].u, edges[i].v);
            mst_weight += edges[i].w;
            edges[i].is_mst = true;
            adj[edges[i].u].push_back({edges[i].v, edges[i].w});
            adj[edges[i].v].push_back({edges[i].u, edges[i].w});
            edges_used++;
        }
    }

    dfs(1, 1, 0, 0);

    long long w2 = INF;
    bool found = false;

    for (int i = 0; i < m; i++)
    {
        if (!edges[i].is_mst)
        {
            int max_val = getmax(edges[i].u, edges[i].v);
            long long w = mst_weight - max_val + edges[i].w;

            if (w >= mst_weight)
            {
                w2 = min(w2, w);
                found = true;
            }
        }
    }

    cout << w2;
    return 0;
}

/*
5 5 2
1 2 2
1 3 4
2 4 3
2 5 1
3 5 5
*/