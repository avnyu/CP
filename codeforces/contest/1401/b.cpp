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

void cal(vll &x, vll &y, int px, int py, ll &ans) {
    ll tmp = min(x[px], y[py]);
    ans += tmp * (px > py ? px * py : px == py ? 0 : -px * py);
    x[px] -= tmp;
    y[py] -= tmp;
}
void solve() {
    vll x(3), y(3);
    for (int i = 0; i < 3; ++i) cin >> x[i];
    for (int i = 0; i < 3; ++i) cin >> y[i];
    ll ans = 0;

    cal(x, y, 2, 1, ans);
    cal(x, y, 1, 1, ans);
    cal(x, y, 1, 0, ans);
    cal(x, y, 0, 2, ans);
    cal(x, y, 2, 2, ans);
    cal(x, y, 2, 0, ans);
    cal(x, y, 0, 0, ans);
    cal(x, y, 0, 1, ans);
    cal(x, y, 1, 2, ans);

    print(ans);
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