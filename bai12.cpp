#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* --------- modpow --------- */
ll modpow(ll a, ll e, ll mod) {
    ll r = 1;
    while (e) {
        if (e & 1) r = (__int128)r * a % mod;
        a = (__int128)a * a % mod;
        e >>= 1;
    }
    return r;
}

/* --------- Tonelli–Shanks ---------
   tìm x sao cho x^2 ≡ n (mod p), p là số nguyên tố lẻ
*/
ll tonelli(ll n, ll p) {
    if (n == 0) return 0;
    if (modpow(n, (p - 1) / 2, p) != 1) return -1;

    if (p % 4 == 3)
        return modpow(n, (p + 1) / 4, p);

    ll q = p - 1, s = 0;
    while ((q & 1) == 0) q >>= 1, s++;

    ll z = 2;
    while (modpow(z, (p - 1) / 2, p) != p - 1) z++;

    ll c = modpow(z, q, p);
    ll x = modpow(n, (q + 1) / 2, p);
    ll t = modpow(n, q, p);
    ll m = s;

    while (t != 1) {
        ll i = 1;
        ll tt = t * t % p;
        while (tt != 1) {
            tt = tt * tt % p;
            i++;
        }
        ll b = modpow(c, 1LL << (m - i - 1), p);
        x = x * b % p;
        t = t * b % p * b % p;
        c = b * b % p;
        m = i;
    }
    return x;
}

/* --------- Cornacchia ---------
   tìm (x,y) sao cho x^2 + y^2 = p, p ≡ 1 (mod 4)
*/
pair<ll,ll> cornacchia(ll p) {
    ll r = tonelli(p - 1, p); // sqrt(-1 mod p)
    if (r == -1) return {-1, -1};

    ll r0 = p, r1 = r;
    while (r1 * r1 > p) {
        ll r2 = r0 % r1;
        r0 = r1;
        r1 = r2;
    }

    ll x = r1;
    ll y2 = p - x * x;
    ll y = sqrt(y2);
    if (y * y != y2) return {-1, -1};
    return {x, y};
}

/* --------- nhân Gaussian --------- */
pair<ll,ll> mul(pair<ll,ll> A, pair<ll,ll> B) {
    return {
        llabs(A.first * B.first - A.second * B.second),
        llabs(A.first * B.second + A.second * B.first)
    };
}

/* --------- phân tích nguyên tố --------- */
map<ll,int> factorize(ll n) {
    map<ll,int> f;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            f[i]++;
            n /= i;
        }
    }
    if (n > 1) f[n]++;
    return f;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    auto fac = factorize(n);

    /* kiểm tra điều kiện Fermat–Euler */
    for (auto [p, e] : fac) {
        if (p % 4 == 3 && (e & 1)) {
            cout << "Impossible\n";
            return 0;
        }
    }

    pair<ll,ll> cur = {1, 0};

    for (auto [p, e] : fac) {
        if (p == 2) {
            pair<ll,ll> base = {1, 1};
            for (int i = 0; i < e; i++)
                cur = mul(cur, base);
        }
        else if (p % 4 == 1) {
            auto base = cornacchia(p);
            if (base.first == -1) {
                cout << "Impossible\n";
                return 0;
            }
            for (int i = 0; i < e; i++)
                cur = mul(cur, base);
        }
        // p ≡ 3 (mod 4) → mũ chẵn → bỏ qua
    }

    ll a = cur.first, b = cur.second;

    /* dựng hình vuông */
    cout << "0 0\n";
    cout << a << " " << b << "\n";
    cout << a - b << " " << a + b << "\n";
    cout << -b << " " << a << "\n";

    return 0;
}
