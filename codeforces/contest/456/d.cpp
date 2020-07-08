#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define lli long long

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct TRIE {
    vector<TRIE *> next;
    int cnt;
    TRIE() {
        next.resize(128, nullptr);
        cnt = 0;
    }
    void add(string &s, int p = 0) {
        if (p == s.size()) return;
        if (!next[s[p]]) {
            next[s[p]] = new TRIE;
            cnt++;
        }
        next[s[p]]->add(s, p + 1);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int n, k;
    cin >> n >> k;

    TRIE *r;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        r->add(s);
    }

    return 0;
}