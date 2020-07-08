#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
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
#define what_is(x) cerr << #x << " is " << x << endl;

using namespace std;

void write();
template <typename T, typename... Args>
void write(T x, Args... args);
template <typename T>
void print_all(vector<T>& a);

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vvi g(128);
    set<ii> lef, rig;
    for (int i = 0; i < n; ++i) {
        g[s[i]].pb(i);
        lef.insert({i, s[i]});
        rig.insert({-i, s[i]});
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int c = 125; c > 96; --c) {
            bool chk = true;
            for (auto p : g[c]) {
                if (lef.find({p, c}) == lef.end()) continue;

                auto l = lef.upper_bound({p, c});
                auto r = rig.upper_bound({-p, c});

                if (l != lef.end() && l->se == c - 1) {
                    ++res;
                    lef.erase({p, c});
                    rig.erase({-p, c});
                    chk = false;
                } else if (r != rig.end() && r->se == c - 1) {
                    ++res;
                    lef.erase({p, c});
                    rig.erase({-p, c});
                    chk = false;
                }
            }
            if (!chk) break;
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
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
    for (auto i = a.begin(); i != a.end();) cout << *i << " \n"[++i == a.end()];
}