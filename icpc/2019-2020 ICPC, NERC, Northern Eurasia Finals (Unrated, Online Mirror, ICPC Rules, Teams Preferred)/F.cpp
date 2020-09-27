#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define lli long long

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

pair<int, int> rem(multiset<int>& s, multiset<int>& h, multiset<int>& a,
                   int& pf) {
    if (s.empty() || h.empty()) return {0, 0};

    int u = *h.begin();
    int v = *s.begin();

    // cout << u << ' ' << v << ' ' << pf << '\n';

    s.erase(s.begin());
    h.erase(h.begin());

    if (h.empty() && pf) {
        h.insert(u);
        pf--;
        // cout << "add h " << u << '\n';
    } else if (h.find(u) == h.end()) {
        a.insert(u);
        // cout << "add s " << u << '\n';
    }

    return {u, v};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, ka, kb;
    cin >> n >> m >> ka >> kb;

    vector<int> a(n), b(m);
    multiset<int> sa, sb;
    multiset<int> ha, hb;

    iota(a.begin(), a.end(), 1);
    iota(b.begin(), b.end(), n + 1);

    for (auto& i : a) sa.insert(i);
    for (auto& i : b) sb.insert(i);

    for (int i = 0; i < ka; ++i) {
        int x;
        cin >> x;
        ha.insert(x);
        sa.erase(x);
    }
    for (int i = 0; i < kb; ++i) {
        int x;
        cin >> x;
        hb.insert(x);
        sb.erase(x);
    }

    vector<pair<int, int>> res;

    int pf = n + m - 2 - ka - kb;
    for (int i = 2; i < n + m; ++i) {
        if (sa.empty())
            res.emplace_back(rem(sb, ha, sa, pf));
        else if (sb.empty())
            res.emplace_back(rem(sa, hb, sb, pf));
        else if ((*sa.begin()) < (*sb.begin()))
            res.emplace_back(rem(sa, hb, sb, pf));
        else
            res.emplace_back(rem(sb, ha, sa, pf));

        if (res.back() == make_pair(0, 0)) {
            cout << "No\n";
            return 0;
        }
        // cout << "sa";
        // for (auto& i : sa) cout << ' ' << i;
        // cout << '\n';

        // cout << "sb";
        // for (auto& i : sb) cout << ' ' << i;
        // cout << '\n';
    }

    // cout << "sa";
    // for (auto& i : sa) cout << ' ' << i;
    // cout << '\n';

    // cout << "sb";
    // for (auto& i : sb) cout << ' ' << i;
    // cout << '\n';

    if (sa.empty() || sb.empty()) {
        cout << "No\n";
        return 0;
    }

    if ((*sb.begin()) != n + m) {
        cout << "No\n";
        return 0;
    }

    res.emplace_back(make_pair(*sa.begin(), *sb.begin()));

    cout << "Yes\n";
    for (auto& i : res) cout << i.first << ' ' << i.second << '\n';

    return 0;
}