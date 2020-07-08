#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define iiii tuple<int, int, int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define fi first
#define se second
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b

using namespace std;

struct prime {
    int N;
    vector<int> primes, minPrime, a;
    prime(int n = 0) {
        N = n;
        iota(minPrime.begin(), minPrime.end(), 0);
        for (int i = 2; i < N; ++i) {
            if (minPrime[i] == i)
                for (int j = i * i; j < N; j += i)
                    if (minPrime[j] == j) minPrime[j] = i;
        }
        a = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
    }
    ll fpow(ll b, ll n, ll m) {
        ll res = 1;
        while (n) {
            if (n & 1) res = (res * b) % m;
            n >>= 1;
            b = (b * b) % m;
        }
        return res;
    }
    void getPrimes() {
        for (int i = 2; i < N; ++i)
            if (minPrime[i] == i) primes.emplace_back(i);
    }
    bool test(ll a, ll s, ll n, ll d) {
        ll p = fpow(a, d, n);
        if (a == n) return true;
        if (p == 1) return true;
        for (; s--;) {
            if (p == n - 1) return true;
            p = (p * p) % n;
        }
        return false;
    }
    bool isPrime(ll n) {
        if (n < 2) return false;
        ll s = 0, d = n - 1;
        while (d % 2 == 0) {
            s++;
            d /= 2;
        }
        bool chk = true;
        for (auto& i : a) chk &= test(i, s, n, d);
        return chk;
    }
};

void solve() {
    prime x;
    int n, m;
    cin >> n >> m;
    for (int i = n; i <= m; ++i)
        if (x.isPrime(i)) cout << i << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}