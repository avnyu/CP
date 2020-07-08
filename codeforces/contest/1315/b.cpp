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
#define pb push_back
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b

using namespace std;

void solve() {
    int a, b, p;
    string s;
    cin >> a >> b >> p >> s;
    int n = s.size();
    vector<ll> m(n);
    char prv = 'c';
    for (int i = n - 2; i >= 0; --i) {
        m[i] = m[i + 1];
        if (s[i] != prv) {
            m[i] += (s[i] == 'A' ? a : b);
            prv = s[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (m[i] <= p) {
            cout << i + 1 << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}