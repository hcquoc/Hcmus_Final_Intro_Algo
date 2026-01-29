#include <iostream>
#include <vector>

using namespace std;

const int N = 2e5 + 5;
const int M = 2e5 + 5;

int n, m;
vector<pair<int, int>> adj[N];
vector<pair<int, int>> edges;

int num_cc;
int sz_cc[N], where[N];
int p[N];
int tin[N], low[N], timer;
int sz[N];
bool vis[M];
bool bridge[M];

void dfs(int u)
{
   tin[u] = low[u] = ++timer;
   sz[u] = 1;
   ++sz_cc[num_cc];
   where[u] = num_cc;
   for (auto [v, i] : adj[u])
   {
      if (vis[i])
         continue;
      vis[i] = true;
      if (!tin[v])
      {
         p[v] = u;
         dfs(v);
         sz[u] += sz[v];
         low[u] = min(low[u], low[v]);
         if (low[v] > tin[u])
         {
            bridge[i] = true;
         }
      }
      else
      {
         low[u] = min(low[u], tin[v]);
      }
   }
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cin >> n >> m;
   for (int i = 0; i < n; i++)
   {
      int u, v;
      cin >> u >> v;
      --u;
      --v;
      adj[u].push_back({v, i});
      adj[v].push_back({u, i});
      edges.push_back({u, v});
   }
   for (int u = 0; u < n; u++)
   {
      if (!tin[u])
      {
         dfs(u);
         ++num_cc;
      }
   }
   long long ans = 0;
   for (int i = 0; i < num_cc; i++)
   {
      ans += 1ll * sz_cc[i] * (n - sz_cc[i]);
   }
   ans /= 2;
   for (int i = 0; i < m; i++)
   {
      if (!bridge[i])
      {
         cout << ans << '\n';
      }
      else
      {
         int u = edges[i].first, v = edges[i].second;
         if (v == p[u])
            swap(u, v);
         cout << ans + 1ll * sz[v] * (sz_cc[where[v]] - sz[v]) << '\n';
      }
   }
}