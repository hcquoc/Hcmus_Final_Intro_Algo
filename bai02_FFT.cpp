// Dùng FFT 

#include<bits/stdc++.h>

using namespace std;

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> &a, bool invert) {
    int n = a.size();
    if (n == 1) return;
    vector<cd> a0(n/2), a1(n/2);
    for (int i = 0; i * 2 < n; i++) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }
    fft(a0, invert);
    fft(a1, invert);
    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if(invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

vector<cd> multiply(vector<cd> &a, vector<cd> &b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++) {
        fa[i] *= fb[i];
    }
    fft(fa, true);
    vector<cd> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = round(fa[i].real());
    }
    return res;
}

vector<bool> isPrime;
void sieve(int maxN) {
    isPrime.assign(maxN + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= maxN; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= maxN; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

vector<cd> buildPrimePolynomial(int maxN) {
    vector<cd> A(maxN + 1);
    for (int i = 2; i <= maxN; i++) {
        if (isPrime[i]) A[i] = 1.0;
    }
    return A;
}


int main()
{
    int n;
    cin >> n;
    int maxVal = 2 * n;
    sieve(maxVal);
    vector<cd> A = buildPrimePolynomial(maxVal);
    vector<cd> C = multiply(A, A);

    long long f = 0;
    for (int k = 2; k <= n; k++) {
        int s = 2 * k;
        long long cnt = (long long) round(C[s].real());

        if (s % 2 == 0 && isPrime[s / 2]) {
            cnt--;              // loại (p,p)
            cnt /= 2;           // chia đôi các cặp còn lại
            cnt++;              // cộng lại (p,p)
        } else {
          cnt /= 2;
        }
        f += cnt;
    }

    cout << f << '\n';
    return 0;
}