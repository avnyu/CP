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

const int M = 1e9 + 7;

int fpow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = (1LL * res * x) % M;
        y >>= 1;
        x = (1LL * x * x) % M;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t;
    cin >> t;
    while (t--) {
        int n, m, M = 1e9 + 7;
        cin >> n >> m;
        cout << (1LL * fpow(3, n + m) * (fpow(2, n * m))) % M << '\n';
    }

    return 0;
}