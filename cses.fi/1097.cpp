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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<pair<ll, ll>>> res(n,
                                     vector<pair<ll, ll>>(n, {-1e18, -1e18}));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j + i < n; ++j) {
            if (i == 0) {
                res[j][j] = {a[j], 0};
                continue;
            }

            int l = j, r = j + i;
            if (res[l][r - 1].se + a[r] > res[l][r].fi)
                res[l][r] = {res[l][r - 1].se + a[r], res[l][r - 1].fi};

            if (res[l + 1][r].se + a[l] > res[l][r].fi)
                res[l][r] = {res[l + 1][r].se + a[l], res[l + 1][r].fi};
        }

    // for (int i = 0; i < n; ++i)
    //     for (int j = i; j < n; ++j) write(i, j, res[i][j].fi, res[i][j].se);

    write(res[0][n - 1].fi);
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