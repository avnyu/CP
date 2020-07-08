#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
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

int cal2(int a[], int l, int r) {
    int mx = 0, mn = 1e9;
    for (int i = l; i <= r; ++i) {
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    //cout << l << ' ' << r << ' ' << mx - mn << '\n';
    return (mx - mn == r - l);
}

int cal(int a[], int l) {
    int res = 0;
    for (int i = 0; i < l; ++i)
        for (int j = i; j < l; ++j) {
            res += cal2(a, i, j);
        }
    return res;
}

void solve() {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int cnt = 0;
    while (1) {
        cnt += cal(a, 7);
        if (!next_permutation(a, a + 7))
            break;
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}