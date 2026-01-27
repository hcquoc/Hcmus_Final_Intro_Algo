#include<bits/stdc++.h>

using namespace std;

vector<int> prefix_function(const string &s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[j] != s[i]) 
            j = pi[j - 1];
        if (s[i] == s[j]) 
            j++;
        pi[i] = j;
    }
    return pi;
}

vector<int> kmp(const string &s, const string &t) {
    int n = s.size();
    int m = t.size();

    vector<int> pi = prefix_function(s);
    vector<int> res;
    int j = 0;
    for (int i = 0; i < m; i++) {
        while(j > 0 && s[j] != t[i])
            j = pi[j - 1];
        if (t[i] == s[j]) 
            j++;
        if (j == n)
            res.push_back(i - n + 1);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string a, b;
    cin >> a >> b;

    vector<int> res = kmp(b, a);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
    }
    return 0;
}