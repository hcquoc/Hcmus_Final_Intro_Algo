#include<bits/stdc++.h>

using namespace std;

vector<int> get_divisors(int n) {
    vector<int> divisors;
    for (int d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            divisors.push_back(d);
            if (d != n / d) divisors.push_back(n / d);
        }
    }
    return divisors;
}




int main()
{


    return 0;
}