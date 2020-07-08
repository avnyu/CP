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
    string s;
    cin >> s;

    s = "xx" + s + "xx";
    int n = s.size();
    vector<int> res;

    for (int i = 2; i < n - 2; ++i) {
        if (s[i - 2] == 't' && s[i - 1] == 'w' && s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e') {
            res.push_back(i - 1);
            s[i] = 'x';
        }
    }

    for (int i = 2; i < n - 2; ++i) {
        if (s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e') {
            res.push_back(i);
            s[i] = 'x';
        }
        if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o') {
            res.push_back(i);
            s[i] = 'x';
        }
    }
    cout << res.size() << '\n';
    for (int i = 0; i < res.size(); ++i) cout << res[i] << " \n"[i == res.size() - 1];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}