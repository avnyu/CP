#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define iiii tuple<int, int, int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define fi first
#define se second
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b

using namespace std;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (auto& i : a) cin >> i;
    vi b(n), c(b);
    iota(all(b), 0);
    iota(rall(c), 0);
    for (int i = 0; i < n; ++i) {
        if (a[i] < b[i]) b[i] = -1;
        if (a[i] < c[i]) c[i] = -1;
    }
    for (int i = 1; i < n; ++i)
        if (b[i - 1] == -1) b[i] = -1;
    for (int i = n - 1; i; --i)
        if (c[i] == -1) c[i - 1] = -1;
    for (int i = 0; i < n; ++i)
        if (b[i] != -1 && c[i] != -1) {
            cout << "Yes\n";
            return;
        }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}