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


