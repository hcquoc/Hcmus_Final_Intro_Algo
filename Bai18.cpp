#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string start = "";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        start += char('0' + x);
    }
    string target = "";
    for (int i = 1; i <= n; i++)
        target += char('0' + i);

    queue<string> q;
    map<string, int> dist;
    q.push(start);
    dist[start] = 0;

    while (!q.empty())
    {
        string cur = q.front();
        q.pop();

        if (cur == target)
        {
            cout << dist[cur];
            return 0;
        }

        for (int i = 1; i < n; i++)
        {
            string nxt = cur;
            reverse(nxt.begin(), nxt.begin() + i + 1);
            // cout<<nxt<<endl;
            if (!dist.count(nxt))
            {
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }

    cout << -1;
}