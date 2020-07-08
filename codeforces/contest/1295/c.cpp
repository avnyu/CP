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
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    string s, t;
    cin >> s >> t;
    vvi pos(26);
    for (int i = 0; i < s.size(); ++i) pos[s[i] - 97].eb(i);
    // for (int i = 0; i < 26; ++i)
    //     if (pos[i].size()) {
    //         cout << char(i + 97) << '\n';
    //         for (int j = 0; j < pos[i].size(); ++j)
    //             cout << pos[i][j] << " \n"[j == pos[i].size() - 1];
    //     }

    int u = -1, res = 1;
    for (int i = 0; i < t.size(); ++i) {
        vi &x = pos[t[i] - 97];
        if (x.empty()) {
            cout << "-1\n";
            return;
        }

        u = upper_bound(all(x), u) - x.begin();
        if (u == x.size()) {
            res++;
            u = upper_bound(all(x), -1) - x.begin();
        }
        u = x[u];
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}