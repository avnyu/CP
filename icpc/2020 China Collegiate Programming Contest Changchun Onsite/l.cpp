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

bool cmp(ll x, ll s, ll n, ll a) {
    return log2(x) > max(log2(s) + log2(n), log2(n) + log2(n - 1) + log2(a) - log2(2));
}
ll sum(ll s, ll n, ll a) {
    if (n & 1) return s * n + (n - 1) / 2 * n * a;
    return s * n + n / 2 * (n - 1) * a;
}
void solve() {
    ll n, k, s;
    cin >> n >> k >> s;

    ll lef = 0, rig = 0, add = 1LL << 60;
    while (add) {
        if (cmp(s, lef + add, n, 1)) lef += add;
        if (cmp(s, rig + add, n, -k)) rig += add;
        add >>= 1;
    }

    print(lef, rig);
    print(sum(lef, n, -k), sum(lef, n, 1));
    print(sum(rig, n, -k), sum(rig, n, 1));
    print(rig - lef);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
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