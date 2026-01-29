#include <iostream>
#include <vector>

using namespace std;

const long long NEG = -1e18;

int main()
{
    int k, n, m;
    cin >> k >> n >> m;

    vector<int> a(k + 1), b(k + 1);
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i] >> b[i];
    }

    vector<vector<vector<long long>>> dp(
        k + 1, vector<vector<long long>>(n + 1, vector<long long>(m + 1, NEG)));

    dp[0][0][0] = 0;

    for (int i = 1; i <= k; i++)
    {
        for (int x = 0; x <= n; x++)
        {
            for (int y = 0; y <= m; y++)
            {
                // Khong chon
                dp[i][x][y] = dp[i - 1][x][y];

                // Chon nhom 1
                if (x > 0 && dp[i - 1][x - 1][y] != NEG)
                    dp[i][x][y] = max(dp[i][x][y],
                                      dp[i - 1][x - 1][y] + a[i]);

                // Chon nhom 2
                if (y > 0 && dp[i - 1][x][y - 1] != NEG)
                    dp[i][x][y] = max(dp[i][x][y],
                                      dp[i - 1][x][y - 1] + b[i]);
            }
        }
    }

    cout << dp[k][n][m];
}






// Truy vết
// void Try(int i, int x, int y)
// {
//     if (i == 0)
//         return;

//     if (dp[i][x][y] == dp[i - 1][x][y])
//     {
//         Try(i - 1, x, y);
//     }
//     else if (x > 0 && dp[i][x][y] == dp[i - 1][x - 1][y] + a[i])
//     {
//         q1.push_back(i);
//         Try(i - 1, x - 1, y);
//     }
//     else if (y > 0 && dp[i][x][y] == dp[i - 1][x][y - 1] + b[i])
//     {
//         q2.push_back(i);
//         Try(i - 1, x, y - 1);
//     }
// }





// minHeap
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <queue>

// using namespace std;

// struct ii {
//     long long a, b, diff;
// };

// bool cmp(const ii &x, const ii &y) {
//     return x.diff > y.diff;
// }

// int main() {
//     int k, n, m;
//     cin>>k>>n>>m;

//     vector<ii> c(k);
//     for (int i = 0; i < k; i++) {
//         cin>>c[i].a>>c[i].b;
//         c[i].diff = c[i].a - c[i].b;
//     }

//     sort(c.begin(), c.end(), cmp);

//     vector<long long> L(k + 1, 0);
//     priority_queue<long long, vector<long long>, greater<long long>> pq1;
//     long long current_sum_a = 0;

//     for (int i=0;i<k;i++) {
//         current_sum_a += c[i].a;
//         pq1.push(c[i].a);
//         if (pq1.size()>n) {
//             current_sum_a -= pq1.top();
//             pq1.pop();
//         }
//         if (pq1.size() == n) L[i] = current_sum_a;
//         else L[i] = -1;
//     }
    
//     vector<long long> R(k + 1, 0);
//     priority_queue<long long, vector<long long>, greater<long long>> pq2;
//     long long current_sum_b = 0;

//     for (int i=k-1;i>=0;i--) {
//         current_sum_b += c[i].b;
//         pq2.push(c[i].b);
//         if (pq2.size() > m) {
//             current_sum_b -= pq2.top();
//             pq2.pop();
//         }
//         if (pq2.size() == m) R[i] = current_sum_b;
//         else R[i] = -1; 
//     }

//     long long max_total = 0;
//     for (int i = n - 1; i < k - m; i++) {
//         if (L[i] != -1 && R[i + 1] != -1) {
//             max_total = max(max_total, L[i] + R[i + 1]);
//         }
//     }

//     cout<<max_total<<endl;

//     return 0;
// }