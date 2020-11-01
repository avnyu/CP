#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvii vector<vector<ii>>
#define vvll vector<vector<ll>>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

ll fpow(ll b, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * b;
        b = b * b;
        n >>= 1;
    }
    return res;
}
void solve() {
    ll p, q;
    cin >> p >> q;
    ll sav = p;
    if (p % q)
        print(p);
    else {
        ll res = 0;
        for (ll i = 2; i < int(1e5); ++i) {
            if (q % i == 0) {
                ll cntp = 0, cntq = 0;
                while (q % i == 0) {
                    cntq++;
                    q /= i;
                }
                while (p % i == 0) {
                    cntp++;
                    p /= i;
                }
                res = max(res, sav / fpow(i, cntp - cntq + 1));
            }
        }
        if (q > 1) {
            ll cntp = 0, cntq = 1;
            while (p % q == 0) {
                cntp++;
                p /= q;
            }
            res = max(res, sav / fpow(q, cntp - cntq + 1));
        }
        print(res);
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}

void print() { cout << "\n"; }
template <typename T, typename... Args>
void print(T x, Args... args) {
    if (sizeof...(args)) {
        cout << x << ' ';
        print(args...);
    } else {
        cout << x << '\n';
    }
}