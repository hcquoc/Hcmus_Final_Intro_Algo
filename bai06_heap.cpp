#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    int row; 
    int idx;

    bool operator > (const Node& other) const {
        return val > other.val;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int k;
    cin >> k;
    cin.ignore();
    vector<vector<int>> a(k);

    for (int i = 0; i < k; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int x;
        while (ss >> x)
            a[i].push_back(x);  
    }   

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    for (int i = 0; i < k; i++) {
        if (!a[i].empty()) {
            pq.push({a[i][0], i, 0});
        }
    }

    while(!pq.empty()) {
        Node cur = pq.top(); 
        pq.pop();
        cout << cur.val << ' ';
        int r = cur.row;
        int c = cur.idx;
        if (c + 1 < (int)a[r].size()) {
            pq.push({a[r][c + 1], r, c + 1});
        }
    }

    return 0;
}