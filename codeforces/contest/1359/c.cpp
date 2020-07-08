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
    ll h, c, t;
    cin >> h >> c >> t;

    float dis = 1e9;
    ll res = -1;

    ll l = 0, r = 1e9;
    while (l <= r) {
        ll m = l + r >> 1;

        float tmp =
            abs((float)(h + h * m + c * m - t * (1 + m + m))) / (1 + m + m);
        if (tmp < dis) {
            res = 1 + m + m;
            dis = tmp;
        } else if (tmp == dis)
            res = min(res, 1 + m + m);

        if (h + h * m + c * m > t * (1 + m + m))
            l = m + 1;
        else
            r = m - 1;
    }

    if (abs(double(h + c) / 2 - t) < dis) res = 2;

    print(res);
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
    cout << x << ' ';
    print(args...);
}
