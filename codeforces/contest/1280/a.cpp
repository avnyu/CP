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

int N = 1e6 + 7;
vector<int> a(N);

void solve() {
    int x;
    string s;
    cin >> x >> s;

    int n = s.size();
    ll res = n, M = 1e9 + 7;

    for (int i = 0; i < n; ++i) a[i] = s[i] - '0';

    int l = 0;
    while (l < x) {
        l++;

        int nn = n;
        for (int i = 0; i < a[l - 1] - 1; ++i)
            for (int j = l; j < n && nn < x; ++j) {
                a[nn++] = a[j];
            }

        ll tmp = res;
        res = (res + 1LL * (a[l - 1] - 1) * (res - l + M)) % M;

        n = nn;
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}