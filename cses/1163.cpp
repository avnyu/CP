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
    int x;
    cin >> x;
    int n;
    cin >> n;
    vi p(n), res(n);
    for (auto& i : p) cin >> i;
 
    vi t = p;
    t.push_back(0);
    t.push_back(x);
    sort(all(t));
 
    set<ii> s;
    int cur = 0;
    for (int i = 1; i < t.size(); ++i) {
        s.insert({t[i - 1], t[i]});
        cur = max(cur, t[i] - t[i - 1]);
    }
    // for (auto& i : s) { print(i.fi, i.se); }
 
    for (int i = n; i--;) {
        res[i] = cur;
 
        int l = p[i], r = p[i];
        auto pr = s.lower_bound({p[i], 0});
 
        if (pr != s.begin()) {
            auto pl = pr;
            --pl;
            if (pl->se == p[i]) {
                l = pl->fi;
                // print(i, "erase l", pl->fi, pl->se);
                s.erase(pl);
            }
        }
        if (pr != s.end() && pr->fi == p[i]) {
            r = pr->se;
            // print(i, "erase r", pr->fi, pr->se);
            s.erase(pr);
        }
        s.insert({l, r});
        // print(i, "insert", l, r);
        cur = max(cur, r - l);
    }
    for (int i = 0; i < n; ++i) cout << res[i] << " \n"[i == n - 1];
 
    // for (auto& i : s) { print(i.fi, i.se); }
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
    if (sizeof...(args)) {
        cout << x << ' ';
        print(args...);
    } else {
        cout << x << '\n';
    }
}