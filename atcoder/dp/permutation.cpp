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

bool chk(vector<char>& a, int p[]) {
    for (int i = 0; i < 4; ++i) {
        if (p[i] > p[i + 1] && a[i] == '<') return false;
        if (p[i] < p[i + 1] && a[i] == '>') return false;
    }
    return true;
}

void test(vector<char>& a, int i) {
    if (i == 4) {
        int p[] = {0, 1, 2, 3, 4};
        int cnt = 0;
        while (1) {
            if (chk(a, p)) {
                // cout << a[0] << a[1] << a[2] << " - " << p[0] << ' ' << p[1] << ' ' << p[2] << ' ' << p[3] << '\n';
                cnt++;
            }
            if (!next_permutation(p, p + 5)) break;
        }
        cout << a[0] << a[1] << a[2] << a[3] << " : " << cnt << '\n';
        return;
    }
    a[i] = '<';
    test(a, i + 1);
    a[i] = '>';
    test(a, i + 1);
}
void solve() {
    int i = 0;
    vector<char> a(10);
    test(a, 0);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}