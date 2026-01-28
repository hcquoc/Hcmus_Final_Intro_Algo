#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <climits>

using namespace std;

void Binary(int m, int n, vector<long long>& A, vector<pair<long long, int>>& B) {
    sort(B.begin(), B.end());
    long long res = LLONG_MAX;
    int idxA = -1, idxB = -1;

    for (int i=0;i<m;i++){
        long long val = -A[i];
        int pos = lower_bound(B.begin(), B.end(), make_pair(val, -1)) - B.begin();
        if (pos < n){
            long long curr = abs(A[i] + B[pos].first);
            if (curr < res){
                res = curr;
                idxA = i;
                idxB = B[pos].second;
            }
        }
        if (pos > 0){
            long long curr = abs(A[i] + B[pos-1].first);
            if (curr < res){
                res = curr;
                idxA = i;
                idxB = B[pos-1].second;
            }
        }
    }
    cout << idxA+1 << " " << idxB+1 << "\n";
}

int main(){
    int n,m;
    cin >> m >> n;
    vector<long long> A(m);
    for (int i = 0; i < m; i++)  cin >> A[i];
    
    vector<pair<long long, int>> B(n);
    for (int i = 0; i < n; i++) {
        cin >> B[i].first;
        B[i].second = i;
    }
    Binary(m, n, A, B);
    return 0;
}