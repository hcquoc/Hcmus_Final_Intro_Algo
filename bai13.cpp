#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n;
    cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    int need = (n - 2) / 2;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            vector<double> ang;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                double vx = p[k].x - p[i].x;
                double vy = p[k].y - p[i].y;
                double ux = p[j].x - p[i].x;
                double uy = p[j].y - p[i].y;

                // Góc từ AB tới Ak
                double angle = atan2(
                    ux * vy - uy * vx,
                    ux * vx + uy * vy
                );
                if (angle < 0) angle += 2 * M_PI;
                ang.push_back(angle);
            }

            sort(ang.begin(), ang.end());

            int m = ang.size();
            for (int start = 0; start < m; start++) {
                int cnt = 1;
                for (int t = start + 1; t < m; t++) {
                    if (ang[t] - ang[start] < M_PI)
                        cnt++;
                    else break;
                }
                if (cnt == need) {
                    cout << i + 1 << " " << j + 1 << "\n";
                    return 0;
                }
            }
        }
    }
    return 0;
}
