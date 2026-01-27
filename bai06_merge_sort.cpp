#include<bits/stdc++.h>
using namespace std;

vector<int> concat(const vector<int> &a, const vector<int> &b) {
    int i = 0, j = 0;
    int n1 = a.size(), n2 = b.size();
    vector<int> c;
    c.reserve(n1 + n2);
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) 
            c.push_back(a[i++]);
        else c.push_back(b[j++]);
    }
    while (i < n1) c.push_back(a[i++]);
    while (j < n2) c.push_back(b[j++]);
    return c;
}

vector<int> merge(const vector<vector<int>> &mat, int lo, int hi) {
    if (lo == hi) return mat[lo];
    int mid = (hi - lo) / 2 + lo;
    vector<int> left = merge(mat, lo, mid);
    vector<int> right = merge(mat, mid + 1, hi);
    return concat(left, right);
}

vector<int> mergeArrays(const vector<vector<int>> &mat) {
    int k = mat.size();
    if (k == 0) return {};
    return merge(mat, 0, k - 1);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif    

    int k;
    cin >> k;
    vector<vector<int>> mat(k);
    for (int i = 0; i < k; i++) {
        string line;
        while (line.empty()) {
            getline(cin, line);
        }
        stringstream ss(line);
        int x;
        while(ss >> x) {
            mat[i].push_back(x);
        }
    }
    vector<int> res = mergeArrays(mat);
    for (int x : res) {
        cout << x << ' ';
    }
    return 0;
}