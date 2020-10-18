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

vii test(vector<vector<char>>& a, ii p1, ii p2, ii p3, ii p4, int v1, int v2,
         int v3, int v4) {
    vii ans;
    if (a[p1.fi][p1.se] != v1) ans.push_back(p1);
    if (a[p2.fi][p2.se] != v2) ans.push_back(p2);
    if (a[p3.fi][p3.se] != v3) ans.push_back(p3);
    if (a[p4.fi][p4.se] != v4) ans.push_back(p4);
    return ans;
}
void solve() {
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) cin >> a[i][j];
    vii ans;
    ans = test(a, {0, 1}, {1, 0}, {n - 1, n - 2}, {n - 2, n - 1}, '1', '1', '0',
               '0');
    if (ans.size() > 2)
        ans = test(a, {0, 1}, {1, 0}, {n - 1, n - 2}, {n - 2, n - 1}, '0', '0',
                   '1', '1');
    print(ans.size());
    for (auto& i : ans) print(i.fi + 1, i.se + 1);
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