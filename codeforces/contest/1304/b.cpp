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
#define rep(i, a, b) for (auto i = a; i != b; i += 1 - 2 * (a > b))

using namespace std;

void solve() {
    int m, n;
    cin >> n >> m;
    set<string> a;
    vector<string> f, l;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        string t(rall(s));
        if (a.find(t) != a.end()) {
            a.erase(t);
            f.push_back(s);
            l.push_back(t);
        } else
            a.insert(s);
    }
    reverse(all(l));
    for (auto& i : a) {
        string j(rall(i));
        if (i == j) {
            cout << m * (f.size() + l.size() + 1) << '\n';
            for (auto& x : f) cout << x;
            cout << i;
            for (auto& x : l) cout << x;
            cout << '\n';
            return;
        }
    }
    cout << m * (f.size() + l.size()) << '\n';
    for (auto& x : f) cout << x;
    for (auto& x : l) cout << x;
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}