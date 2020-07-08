#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define lli long long

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<int> par(27, -1);
vector<int> cnt(27, 0);
vector<int> exist(27, 0);

int root(int u) { return par[u] < 0 ? u : (par[u] = root(par[u])); }
void merge(int u, int v) {
    if ((u = root(u)) == (v = root(v))) return;
    par[u] += par[v];
    par[v] = u;
}

void solve() {
    int n;
    cin >> n;

    for (int k = 0; k < n; ++k) {
        string s;
        cin >> s;

        for (auto& i : cnt) i = 0;
        for (auto& i : s) {
            cnt[i - 97] = 1;
            exist[i - 97] = 1;
        }

        for (int i = 0; i < 27; ++i)
            for (int j = 0; j < 27; ++j)
                if (cnt[i] && cnt[j]) merge(i, j);
    }

    for (int i = 0; i < 27; ++i) exist[i] = (exist[i] ? root(i) : -1);

    sort(exist.begin(), exist.end());
    exist.erase(unique(exist.begin(), exist.end()), exist.end());

    cout << exist.size() - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    solve();

    return 0;
}