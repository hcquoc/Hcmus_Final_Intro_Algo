#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int n;
    long long T;
    cin >> n >> T;
    
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long maxHeight = 0;
    
    for (int i = 0; i < n; i++) {
        long long L = 0, R = a[i];
        long long bestHeight = 0;
        
        while (L <= R) {
            long long X = (L + R) / 2;
            
            long long totalCost = 0;
            for (int j = 0; j < i; j++) {
                long long requiredHeight = X - (i - j);
                if (requiredHeight < 0) requiredHeight = 0;
                
                if (a[j] > requiredHeight) {
                    totalCost += a[j] - requiredHeight;
                }
            }
            
            for (int j = i + 1; j < n; j++) {
                long long requiredHeight = X - (j - i);
                if (requiredHeight < 0) requiredHeight = 0;
                
                if (a[j] > requiredHeight) {
                    totalCost += a[j] - requiredHeight;
                }
            }
            
            totalCost += a[i] - X;
            
            if (totalCost <= T) {
                bestHeight = X;
                L = X + 1;  
            } else {
                R = X - 1; 
            }
        }
        
        maxHeight = max(maxHeight, bestHeight);
    }
    
    cout << maxHeight << endl;
    
    return 0;
}




// #include <iostream>
// #include <cstring>

// using namespace std;
// #define int long long
// const int oo = (int)1e18 + 5;
// const int oo1 = (int)1e17 + 5;
// const int N = (int)1e5 + 5;
// int n, T, a[N], f[N], d[N], l[N], r[N];
// bool check(int h) {
// 	for (int i = 1; i <= n; ++i) {
// 		if (a[i] <= h) return 1;
// 	}
// 	// Với mỗi i, tìm j < i lớn nhất mà a[j] <= h + i - j (vị trí ngừng loang)
// 	memset(d, 0, sizeof d);
// 	for (int j = 1; j <= n; ++j) {
// 		int i = a[j] + j - h;
// 		i = max(i, 1LL);
// 		if (i <= n) d[i] = j;
// 	}
// 	int mx = 0;
// 	for (int i = 1; i <= n; ++i) {
// 		mx = max(mx, d[i]);
// 		l[i] = mx + 1;
// 	}
// 	// Tương tự nhưng tìm i < j nhỏ nhất mà a[j] <= h + j - i
// 	for (int i = 1; i <= n; ++i) {
// 		d[i] = n + 1;
// 	}
// 	for (int j = n; j >= 1; --j) {
// 		int i = h + j - a[j];
// 		i = min(i, n);
// 		if (i >= 1) d[i] = j;
// 	}
// 	int mn = n + 1;
// 	for (int i = n; i >= 1; --i) {
// 		mn = min(mn, d[i]);
// 		r[i] = mn - 1;
// 	}
// 	for (int i = 1; i <= n; ++i) {
// 		int li = l[i], ri = r[i];
// 		int cur = f[ri] - f[li - 1];
// 		cur -= (i - li) * (i - li + 1) / 2;
// 		cur -= (ri - i) * (ri - i + 1) / 2;
// 		if (-h >= (oo + oo1 + ri - li) / (ri - li + 1)) continue;
// 		cur -= h * (ri - li + 1);
// 		if (cur <= T) return 1;
// 	}
// 	return 0;
// }
// signed main() {
// 	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// 	cin >> n >> T;
// 	for (int i = 1; i <= n; ++i) {
// 		cin >> a[i];
// 		f[i] = f[i - 1] + a[i];
// 	}
// 	int l = -oo, r = oo, ans = oo;
// 	while (l <= r) {
// 		int mid = l + (r - l) / 2;
// 		if (check(mid)) {
// 			ans = mid;
// 			r = mid - 1;
// 		}
// 		else l = mid + 1;
// 	}
// 	cout << ans << '\n';
// 	return 0;
// }