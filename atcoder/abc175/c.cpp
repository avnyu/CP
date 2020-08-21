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

void solve() {
    ll x, d, k;
    cin >> x >> k >> d;
    ll t = x / d;
    ll res = abs(x);
    vi a;
    a.push_back(t - 3);
    a.push_back(t - 2);
    a.push_back(t - 1);
    a.push_back(t);
    a.push_back(t + 1);
    a.push_back(t + 2);
    a.push_back(t + 3);
    a.push_back(k - 1);
    a.push_back(k);
    a.push_back(-k + 1);
    a.push_back(-k);
    for (auto& i : a)
        if (abs(i) <= k && abs(i) % 2 == k % 2) res = min(res, abs(x - i * d));

    print(res);
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