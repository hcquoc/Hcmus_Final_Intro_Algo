#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(const vector<int>& a) {
        n = a.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, a);
    }

    void build(int node, int l, int r, const vector<int>& a) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid, a);
        build(node * 2 + 1, mid + 1, r, a);
        tree[node] = gcd(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;   // gcd(x,0) = x
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = (l + r) / 2;
        return gcd(
            query(node * 2, l, mid, ql, qr),
            query(node * 2 + 1, mid + 1, r, ql, qr)
        );
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    SegmentTree st(a);

    int ans = 0;
    for (int i = 0; i + k <= n; i++) {
        int g = st.query(i, i + k - 1);
        ans = max(ans, g);
    }

    cout << ans;
    return 0;
}
