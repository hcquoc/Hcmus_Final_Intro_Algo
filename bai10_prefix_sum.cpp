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

    vector<vector<int>> a(m + 1, vector<int>(n + 1, 0));
    vector<vector<int>> ps(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            ps[i][j] = a[i][j]
                     + ps[i-1][j]
                     + ps[i][j-1]
                     - ps[i-1][j-1];
        }
    }

    int maxLen = 1;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int len = 1; i + len - 1 <= m && j + len - 1 <= n; len++) {
                int x2 = i + len - 1;
                int y2 = j + len - 1;

                int sum = ps[x2][y2]
                        - ps[i-1][y2]
                        - ps[x2][j-1]
                        + ps[i-1][j-1];

                if (sum == 0 || sum == len * len) {
                    maxLen = max(maxLen, len);
                }
            }
        }
    }

    cout << maxLen * maxLen << endl;
    return 0;
}
