#include<bits/stdc++.h>

using namespace std;

int main()
{
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
    int ans = 0;
    for (int i = 0; i < n - k + 1; i++) {
        int g = a[i];
        for (int j = i + 1; j < i + k; j++) {
            g = gcd(g, a[j]);
        }
        ans = max(ans, g);
    }
    cout << ans;
    return 0;
}