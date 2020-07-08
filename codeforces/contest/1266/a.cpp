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
    int rem = 0;
    bool chk = false;
    for (auto& c : s) {
        rem = (rem + (c - '0') * 4) % 6;
        if (c == '0' && !chk) {
            chk = true;
            c = '.';
        }
    }
    for (auto& c : s) {
        if (c == '.') continue;
        if ((rem + 600 - (c - '0') * 3) % 6 == 0 && chk) {
            cout << "red\n";
            return;
        }
    }
    cout << "cyan\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}