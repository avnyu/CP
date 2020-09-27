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

    string s;
    cin >> s;
    int n = s.size();

    auto chk_pan = [&](string &s, int l, int r) {
        while (l < r)
            if (s[l++] != s[r--]) return false;
        return true;
    };

    for (int i = 0; i < n; ++i)
        if (chk_pan(s, i, n - 1)) {
            cout << s;
            for (int j = i - 1; j >= 0; --j) cout << s[j];
            cout << '\n';
            return 0;
        }

    return 0;
}