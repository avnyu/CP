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
    string s;
    cin >> n >> s;

    vector<int> res;
    for (int i = 0; i < n; ++i) s[i] = (s[i] == 'B');
    for (int i = 0; i < n - 1; ++i) {
        if (s[i]) {
            res.push_back(i + 1);
            s[i] = 1 - s[i];
            s[i + 1] = 1 - s[i + 1];
        }
    }

    if (s[n - 1]) {
        for (int i = 0; i < n - 1; ++i) {
            if (!s[i]) {
                res.push_back(i + 1);
                s[i] = 1 - s[i];
                s[i + 1] = 1 - s[i + 1];
            }
        }

        if (!s[n - 1]) {
            cout << "-1\n";
            return;
        }
    }

    cout << res.size() << '\n';
    for (int i = 0; i < res.size(); ++i) cout << res[i] << " \n"[i == res.size() - 1];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    solve();

    return 0;
}