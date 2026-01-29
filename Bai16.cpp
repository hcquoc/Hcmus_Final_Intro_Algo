#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>> &adj, int node)
{
    int n = adj.size();
    vector<int> d(n, -1); //-1 la chua tham
    d[node] = 0;
    queue<int> q;
    q.push(node);
    int res = 0;
    while (!q.empty())
    {
        int root = q.front();
        q.pop();
        res += d[root];
        for (auto e : adj[root])
        {
            if (d[e] == -1)
            {
                q.push(e);
                d[e] = d[root] + 1;
            }
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += bfs(adj, i);
    }
    cout << 0.5 * res;
    return 0;
}

// #include <iostream>
// #include <vector>

// typedef long long ll;
// using namespace std;

// int n;
// vector<int> graph[200001];
// ll dp[200001], ans[200001];

// void dfs1(int node = 1, int parent = 0, ll depth = 0)
// {
//     ans[1] += depth;
//     dp[node] = 1;
//     for (int i : graph[node])
//         if (i != parent)
//         {
//             dfs1(i, node, depth + 1);
//             dp[node] += dp[i];
//         }
// }

// void dfs2(int node = 1, int parent = 0)
// {
//     for (int i : graph[node])
//         if (i != parent)
//         {
//             ans[i] = ans[node] + n - 2 * dp[i];
//             dfs2(i, node);
//         }
// }

// int main()
// {
//     cin >> n;
//     for (int i = 1; i < n; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         graph[a].push_back(b);
//         graph[b].push_back(a);
//     }
//     dfs1();
//     dfs2();
//     ll total = 0;
//     for (int i = 1; i <= n; i++)
//         total += ans[i];
//     cout << total / 2;
//     return 0;
// }