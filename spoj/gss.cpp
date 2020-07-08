#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvii vector<vector<ii>>
#define vvll vector<vector<ll>>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define what_is(x) cerr << #x << " is " << x << endl;

using namespace std;

void write();
template <typename T, typename... Args>
void write(T x, Args... args);

const int N = 1 << 16;
struct node {
    int pre, suf, sum, ans;
    node() {
    }
    node(int v) : pre(v), suf(v), sum(v), ans(v) {
    }
} st[N << 1];
node combine(node lef, node rig) {
    node rs;
    rs.pre = max(lef.pre, lef.sum + rig.pre);
    rs.suf = max(lef.suf + rig.sum, rig.suf);
    rs.sum = lef.sum + rig.sum;
    rs.ans = max(max(lef.ans, rig.ans), lef.suf + rig.pre);
    return rs;
}
node get(int l, int r, int i = 1, int b = 0, int e = N - 1) {
    if (l > e || r < b) return node(-N);
    if (l <= b && e <= r) return st[i];
    int m = b + e >> 1;
    return combine(get(l, r, i << 1, b, m), get(l, r, i << 1 | 1, m + 1, e));
}
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i++ < n;) {
        int x;
        cin >> x;
        st[i + N] = node(x);
    }
    for (int i = N; --i;) st[i] = combine(st[i << 1], st[i << 1 | 1]);
    int m;
    cin >> m;
    for (int i = 0; i++ < m;) {
        int l, r;
        cin >> l >> r;
        write(get(l, r).ans);
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    // clock_t st = clock();

    int t = 1;
    // cin >> t;
    while (t--) solve();

    // write("Time", clock() - st);

    return 0;
}
template <typename T, typename... Args>
void write(T x, Args... args) {
    cout << x;
    if (sizeof...(args)) {
        cout << ' ';
        write(args...);
    } else
        cout << '\n';
}