#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> lg(n + 1);
    lg[1] = 0;
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i / 2] + 1;
    }
    int log = lg[n] + 1;
    vector<vector<int>> st(n, vector<int> (log));

    for (int i = 0; i < n; i++) {
        st[i][0] = a[i];
    }

    for (int j = 1; j < log; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    int ans = 0;
    for (int i = 0; i + k <= n; i++) {
        int p = lg[k];
        int g = gcd(st[i][p], st[i + k - (1 << p)][p]);
        ans = max(ans, g);
    }
    cout << ans;
    return 0;
}