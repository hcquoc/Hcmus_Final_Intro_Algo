#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double x1, y1, x2, y2, R;
    cin >> x1 >> y1 >> x2 >> y2 >> R;

    double dx = x1 - x2;
    double dy = y1 - y2;
    double d = sqrt(dx * dx + dy * dy);

    double area;

    if (d >= 2 * R) {
        // không giao
        area = 2 * M_PI * R * R;
    }
    else if (d == 0) {
        // trùng tâm
        area = M_PI * R * R;
    }
    else {
        double t = sqrt(4 * R * R - d * d);

        double intersection = 2 * R * R * atan(t / d) - d * t / 2.0;
        area = 2 * M_PI * R * R - intersection;
    }
    cout << fixed << setprecision(3) << area << '\n';
    return 0;
}
