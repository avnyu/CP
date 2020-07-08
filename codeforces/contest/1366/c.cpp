#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vector<int>>
#define vvii vector<vector<ii>>
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
template <typename T>
void print_all(vector<T>& a);

void solve() {
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) cin >> a[i][j];

    vvii g(n + m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) g[i + j].push_back({i, j});
    int l = 0, r = n + m - 2;
    vi cnt(2);
    int res = 0;
    while (l < r) {
        fill(all(cnt), 0);
        for (auto& i : g[l]) cnt[a[i.fi][i.se]]++;
        for (auto& i : g[r]) cnt[a[i.fi][i.se]]++;

        res += min(cnt[0], cnt[1]);
        ++l;
        --r;
    }
    write(res);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}

void write() { cout << "\n"; }
template <typename T, typename... Args>
void write(T x, Args... args) {
    cout << x << ' ';
    write(args...);
}
template <typename T>
void print_all(vector<T>& a) {
    for (int i = 0; i < a.size(); ++i) cout << a[i] << " \n"[i == a.size() - 1];
}
