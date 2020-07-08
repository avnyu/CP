#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define iii tuple<int, int, int>
#define ii pair<int, int>
#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    string p, h;
    cin >> p >> h;
    int n = p.size(), m = h.size();
    vector<int> a(128, 0), b(128, 0);
    for (auto& i : p) a[i]++;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 128; ++j) b[j] = 0;

        for (int j = 0; j < n && i + j < m; ++j) b[h[i + j]]++;

        bool chk = true;
        for (int j = 0; j < 128; ++j) chk &= a[j] == b[j];
        if (chk) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}