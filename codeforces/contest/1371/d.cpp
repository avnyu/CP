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
    int n, k;
    cin >> n >> k;
    vvi a(n, vi(n));
    vvi pos(n * n, vi(3));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            pos[i * n + j][0] = abs(j - i);
            pos[i * n + j][1] = j;
            pos[i * n + j][2] = (i + j) % n;
        }
    for (int i = 0; i < k; ++i) a[pos[i][1]][pos[i][2]] = 1;

    int mncol = 1e9, mxcol = 0, mnrow = 1e9, mxrow = 0;
    for (int i = 0; i < n; ++i) {
        int c = 0, r = 0;
        for (int j = 0; j < n; ++j) {
            r += a[i][j];
            c += a[j][i];
        }
        mncol = min(mncol, c);
        mxcol = max(mxcol, c);
        mnrow = min(mnrow, r);
        mxrow = max(mxrow, r);
    }
    ll ans = 0;
    ans = (mxrow - mnrow) * (mxrow - mnrow) + (mxcol - mncol) * (mxcol - mncol);
    print(ans);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) cout << a[i][j] << (j == n - 1 ? "\n" : "");
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