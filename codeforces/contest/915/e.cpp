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
#define rep(i, a, b) for (auto i = a; i != b; i += 1 - 2 * (a > b))

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    set<ii> s;
    for (int i = 0; i < q; ++i) {
        int l, r, k;
        cin >> l >> r >> k;
        r++;
        if (k == 1) {
            auto it = s.lower_bound({l, r});
            if (it != s.begin() && !s.empty()) {
                --it;
                if (it->se >= l) {
                    l = min(it->fi, r);
                    r = max(it->se, r);
                    n += it->se - it->fi;
                    s.erase(it);
                }
            }
            while (1) {
                it = s.lower_bound({l, r});
                if (it == s.end()) break;
                if (it->fi > r) break;
                l = min(it->fi, l);
                r = max(it->se, r);
                n += it->se - it->fi;
                s.erase(it);
            }
            s.insert({l, r});
            n -= r - l;
        } else {
            auto it = s.lower_bound({l, r});
            if (it != s.begin() && !s.empty()) {
                --it;
                if (it->se > l) {
                    if (it->se > r) {
                        ii tmp = {r, it->se};
                        n -= it->se - r;
                        s.insert(tmp);
                    }
                    ii tmp = {it->fi, min(it->se, l)};
                    n += it->se - it->fi;
                    s.erase(it);
                    n -= tmp.se - tmp.fi;
                    s.insert(tmp);
                }
            }
            while (1) {
                it = s.lower_bound({l, r});
                if (it == s.end()) break;
                if (it->fi >= r) break;
                if (it->se <= r) {
                    n += it->se - it->fi;
                    s.erase(it);
                } else {
                    ii tmp = {max(it->fi, r), it->se};
                    n += it->se - it->fi;
                    s.erase(it);
                    n -= tmp.se - tmp.fi;
                    s.insert(tmp);
                }
            }
        }
        cout << n << '\n';
        // for (auto& i : s) cout << i.fi << ' ' << i.se << " - ";
        // cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}