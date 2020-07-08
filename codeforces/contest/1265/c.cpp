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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;

    int g, s, b;
    g = s = b = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1] && g == 0) {
            g = i;
        } else if (a[i] < a[i - 1] && g && i - g > g && s == 0) {
            s = i;
        } else if (a[i] < a[i - 1] && g && s && i - s > g && i + i <= n &&
                   b == 0) {
            b = i;
        } else if (a[i] < a[i - 1] && g && s && b && i + i <= n)
            b = i;
    }

    if (!b)
        cout << "0 0 0\n";
    else
        cout << g << ' ' << s - g << ' ' << b - s << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}