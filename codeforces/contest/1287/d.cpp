#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define iiii tuple<int, int, int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define fi first
#define se second
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2007;
int n, r;
vi c(N), s(N), a(N), used(N);
vvi g(N);

int dfs(int u) {
    for (auto& v : g[u]) s[u] += dfs(v);
    return ++s[u];
}
int find_pos(int k) {
    int j = 1;
    while (k) {
        if (!used[j]) k--;
        if (!k) break;
        j++;
    }
    return j;
}
void cal(int u, int st = 1) {
    if (c[u] >= s[u]) return;
    int p = find_pos(c[u] + 1);
    a[u] = p;
    used[p] = 1;
    for (auto& v : g[u]) {
        cal(v, st);
        st += s[v];
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int pi;
        cin >> pi >> c[i];
        if (pi)
            g[pi].eb(i);
        else
            r = i;
    }
    dfs(r);
    cal(r);
    for (int i = 1; i <= n; ++i)
        if (!a[i]) {
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
    for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}