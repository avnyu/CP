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
    int n;
    cin >> n;
    vvi g(n, vi(3));
    vi x = {0};
    for (auto& i : g) {
        cin >> i[0] >> i[1] >> i[2];
        x.push_back(i[0]);
        x.push_back(i[1] + 1);
    }
    sort(all(x));
    uni(x);

    n = x.size();
    vector<map<int, int>> m(n + 1);
    for (auto& i : g) {
        int l = lower_bound(all(x), i[0]) - x.begin();
        int r = lower_bound(all(x), i[1] + 1) - x.begin();
        m[l][r] = max(m[l][r], i[2]);
    }

    vll dp(n + 1);
    for (int i = 0; i++ < n;) {
        dp[i] = max(dp[i], dp[i - 1]);

        for (auto& j : m[i]) dp[j.first] = max(dp[j.first], dp[i] + j.second);
    }

    print(dp[n]);
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
    cout << x << ' ';
    print(args...);
}