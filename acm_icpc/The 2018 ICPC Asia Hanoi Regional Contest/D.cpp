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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int n;
    cin >> n;
    auto query = [](int x, int n) {
        int M = 1e9, add = int(5e8) - 1;
        cout << "QUERY " << x % M << ' ' << (x + add) % M << endl;
        int res;
        cin >> res;
        if (res + res < n) return -1;
        if (res + res == n) return 0;
        return 1;
    };

    int q = query(0, n), l = 0, r = int(5e8), M = 1e9, cnt = 28;
    if (q == 0) {
        cout << "YES 0\n" << endl;
        return 0;
    }
    if (q > 0) r += int(5e8), l += int(5e8);
    while (cnt--) {
        int m = (l + r) >> 1;
        q = query(m, n);
        if (q == 0) {
            cout << "YES " << m % M << endl;
            return 0;
        }
        if (q < 0) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << "YES " << l << endl;

    return 0;
}