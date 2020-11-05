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
#define pll pair<ll, ll>

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

namespace DCHT {
#define tlll tuple<ll, ll, ll>

}  // namespace DCHT

void solve() {
    int n;
    cin >> n;
    vvll a(n, vll(3));
    for (auto& i : a)
        for (auto& j : i) cin >> j;
    sort(a.begin(), a.end());

    // for (int i = 0; i < n; ++i)
    //     for (int j = 0; j < 3; ++j) cout << a[i][j] << " \n"[j == 2];

    ll res = 0;
    const int maxN = 1e9;
    DLIT::add(1, maxN, pll{0, 0}, 1, 1, maxN);

    for (int i = 0; i < n; ++i) {
        auto &x = a[i][0], &y = a[i][1], &v = a[i][2];

        ll cur = DLIT::query(y, 1, 1, maxN);
        // print("query", y, cur);
        res = max(res, cur + x * y - v);

        // print("add", -x, cur);
        DLIT::add(1, maxN, pll{-x, cur + x * y - v}, 1, 1, maxN);
    }
    print(res);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

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