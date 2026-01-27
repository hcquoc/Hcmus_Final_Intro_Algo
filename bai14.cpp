#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Point {
    ll x, y;
};

ll cross(const Point &a, const Point &b, const Point &c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

ll area(const Point &a, const Point &b, const Point &c) {
    return llabs(cross(a, b, c));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    int n;
    cin >> n;
    vector<Point> p(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
        p[i + n] = p[i];
    }
    ll S = 0;
    for (int i = 1; i < n - 1; i++) {
        S += area(p[0],p[i], p[i + 1]);
    }

    ll curArea = 0, bestDiff = LLONG_MAX;
    int j = 1;
    int ansI = 0, ansJ = 1;
    for (int i = 0; i < n; i++) {
        while (j + 1 < i + n) {
            ll add = area(p[i], p[j], p[j + 1]);
            ll before = llabs(2 * curArea - S);
            ll after = llabs(2 * (curArea + add) - S);
            if (after > before) break;
            S += add;
            j++;
        }
        ll diff = llabs(2 * curArea - S);
        if (diff < bestDiff) {
            bestDiff = diff;
            ansI = i;
            ansJ = j;
        }
        if (j > i + 1) {
            curArea -= area(p[i],p[i + 1], p[j]);
        }
    }
    cout << ansI + 1 << ' ' << ansJ + 1 << '\n';
    return 0;

}