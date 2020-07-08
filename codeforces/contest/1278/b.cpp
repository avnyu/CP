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
    int a, b;
    cin >> a >> b;
    a = abs(a - b);
    for (int i = 0; i <= a + a; ++i) {
        int j = i * (i + 1) / 2;
        cout << i << ' ' << j << '\n';
        if (j >= a && j % 2 == a % 2) {
            cout << i << '\n';
            return;
        }
    }
    cout << "0\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}