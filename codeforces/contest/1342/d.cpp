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
#define what_is(x) cerr << #x << " is " << x << endl;

using namespace std;

void write();
template <typename T, typename... Args>
void write(T x, Args... args);

void solve() {
    int n, k;
    cin >> n >> k;
    vi m(n);
    for (int i = 0; i < n; ++i) cin >> m[i];
    vi c(k);
    for (int i = 0; i < k; ++i) cin >> c[i];

    vi cnt(k + 1, 0);
    for (auto& i : m) cnt[i]++;
    for (int i = k; i--;) cnt[i] += cnt[i + 1];

    int g = 0;
    for (int i = 0; i++ < k;) g = max(g, (cnt[i] - 1) / c[i - 1] + 1);

    write(g);
    vvi ans(g);

    sort(rall(m));

    int i = 0;
    for (auto& x : m) ans[(i++) % g].push_back(x);
    for (auto& x : ans) {
        cout << x.size();
        for (auto& y : x) cout << ' ' << y;
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}
template <typename T, typename... Args>
void write(T x, Args... args) {
    cout << x;
    if (sizeof...(args)) {
        cout << ' ';
        write(args...);
    } else
        cout << '\n';
}