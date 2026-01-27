#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif    
    
    int m, n;
    cin >> m >> n;

    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    vector<vector<int>> dp(m, vector<int>(n, 1));
    int maxLen = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 1;
            } else {
                if (a[i][j] == a[i-1][j] &&
                    a[i][j] == a[i][j-1] &&
                    a[i][j] == a[i-1][j-1]) {

                    dp[i][j] = 1 + min({
                        dp[i-1][j],
                        dp[i][j-1],
                        dp[i-1][j-1]
                    });
                } else {
                    dp[i][j] = 1;
                }
            }
            maxLen = max(maxLen, dp[i][j]);
        }
    }

    cout << maxLen * maxLen << '\n';
    return 0;
}
