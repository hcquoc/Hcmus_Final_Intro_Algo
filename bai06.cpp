#include<bits/stdc++.h>
using namespace std;

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
    vector<int> all;

    for (int i = 0; i < k; i++) {
        string line;
        while(line.empty()) {
            getline(cin, line);
        }
        stringstream ss(line);
        int x;
        while (ss >> x) {
            all.push_back(x);
        }
    }

    sort(all.begin(), all.end());
    for (int x : all) {
        cout << x << ' ';
    }

    return 0;
}