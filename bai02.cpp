#include<bits/stdc++.h>

using namespace std;

vector<bool> isPrime;
void sieve(int maxN) {
    isPrime.assign(maxN + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= maxN; i++) {
        if (isPrime[i]) {
            for(int j = i * i; j <= maxN; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int MAX = 2 * n;
    sieve(MAX);
    vector<int> primes;
    for (int i = 2; i <= MAX; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
    vector<long long> g(n + 1, 0);
    int m = primes.size();
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            int s = primes[i] + primes[j];
            if (s > 2 * n) break;
            if ((s & 1) == 0) {
                int k = s / 2;
                if (k >= 2) g[k]++;
            }
        }
    }

    long long f = 0;
    for (int k = 2; k <= n; k++) {
        f += g[k];
    }
    cout << f << '\n';
    return 0;
}