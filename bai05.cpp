#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string A, B;
    cin >> A >> B;

    int n = A.size();
    int m = B.size();

    bool found = false;

    for (int i = 0; i + m <= n; i++) {
        bool ok = true;
        for (int j = 0; j < m; j++) {
            if (A[i + j] != B[j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << i + 1 << " ";
            found = true;
        }
    }

    return 0;
}
