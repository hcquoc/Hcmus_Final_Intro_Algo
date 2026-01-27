#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> input() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    return a;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif    
    
    vector<vector<int>> a = input();
    int m = a.size();
    int n = a[0].size();
    int maxlen = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int len = 1; i + len <= m && j + len <= n; len++) {
                bool ok = true;
                int val = a[i][j];

                for (int x = i; x < i + len && ok; x++) {
                    for (int y = j; y < j + len; y++) {
                        if (a[x][y] != val) {
                            ok = false;
                            break;
                        }
                    }
                }

                if (ok) maxlen = max(maxlen, len);
            }
        }
    }

    cout << maxlen * maxlen << '\n';
    return 0;
}
