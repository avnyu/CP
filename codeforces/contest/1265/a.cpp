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
    s = 'x' + s + 'x';
    auto choose = [](char l, char r) {
        if (l != 'a' && r != 'a') return 'a';
        if (l != 'b' && r != 'b') return 'b';
        return 'c';
    };

    for (int i = 1; i < s.size() - 1; ++i)
        if (s[i] == '?')
            s[i] = choose(s[i - 1], s[i + 1]);
        else if (s[i] == s[i - 1]) {
            cout << "-1\n";
            return;
        }

    s.erase(s.begin());
    s.pop_back();
    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}