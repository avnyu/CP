#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define iiii tuple<int, int, int, int>
#define iii tuple<int, int, int>
#define ii pair<int, int>
#define fi first
#define vi vector<int>
#define vvi vector<vector<int>>
#define se second

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n + 1, 1);
    for (int i = 0; i < m; ++i) {
        int x;
        string s;
        cin >> x >> s;
        if (s == "WA" && a[x] > 0) a[x]++;
        if (s == "AC" && a[x] > 0) a[x] = -a[x];
    }
    int cor = 0, pen = 0;
    for (int i = 0; i < n + 1; ++i) {
        if (a[i] < 0) {
            cor++;
            pen += -a[i] - 1;
        }
    }
    cout << cor << ' ' << pen << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}