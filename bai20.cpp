#include<bits/stdc++.h>

using namespace std;

vector<int> input() {
    vector<int> p;
    string line;
    getline(cin, line);
    stringstream ss(line);
    int x;
    while (ss >> x) p.push_back(x);
    return p;
}

vector<unsigned long long> factorial(int n) {
    vector<unsigned long long> f(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * i;
    }
    return f;
}

unsigned long long getRank(const vector<int> &p, vector<unsigned long long> &fact) {
    int n = p.size();
    vector<bool> used(n + 1, false);
    unsigned long long rank = 1;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int v = 1; v < p[i]; v++) {
            if (!used[v]) cnt++;
        }
        rank += cnt * fact[n - i - 1];
        used[p[i]] = 1;
    }   
    return rank;
}

vector<int> getPermutationByRank(int n, unsigned long long y, const vector<unsigned long long> &fact) {
    vector<int> a;
    for (int i = 1; i <= n; i++) {
        a.push_back(i);
    }
    vector<int> q;
    y--;
    for (int i = 0; i < n; i++) {
        int index = y / fact[n - i - 1];
        q.push_back(a[index]);
        a.erase(a.begin() + index);
        y %= fact[n - i - 1];
    }
    return q;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    vector<int> p = input();
    int n = p.size();
    unsigned long long y;
    cin >> y;

    vector<unsigned long long> fact = factorial(n);
    unsigned long long rank = getRank(p, fact);
    cout << rank << '\n';
    vector<int> q = getPermutationByRank(n, y, fact);
    for (int i = 0; i < n; i++) {
        cout << q[i];
        if (i + 1 < n) cout << ' ';
    }
    cout << '\n';
    return 0;
}