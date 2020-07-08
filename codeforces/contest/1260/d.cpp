#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define lli long long

using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> ii;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int N = 2e5 + 7;
int m, n, k, t;
vector<int> a;
vector<vector<ii>> b;

bool can_go(int p) {
    int l = 0, c = n + 1;

    while (l <= n) {
        int r = -1;
        for (auto& bi : b[l + 1])
            if (bi.second > p) r = max(r, bi.first);

        if (r == -1) {
            l++;
            continue;
        }

        int i = l + 1;
        while (i <= r) {
            for (auto& bi : b[i])
                if (bi.second > p) r = max(r, bi.first);
            i++;
        }

        c += (r - l) << 1;
        l = r;
    }

    return c <= t;
}

int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    cin >> m >> n >> k >> t;
    a.resize(m);
    b.resize(n + 2);

    for (int i = 0; i < m; ++i) cin >> a[i];
    for (int i = 0; i < k; ++i) {
        int l, r, w;
        cin >> l >> r >> w;
        b[l].push_back({r, w});
    }

    sort(a.rbegin(), a.rend());

    int l = 0, r = m - 1;
    int res = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;

        if (can_go(a[mid])) {
            res = mid + 1;
            l = mid + 1;
        } else
            r = mid - 1;
    }

    cout << res << '\n';

    return 0;
}