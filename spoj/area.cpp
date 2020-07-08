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

const int N = 1 << 15;
struct node {
    int res, min, min_cnt, laz;
    node(int v = 0) {
        res = min = laz = min_cnt = v;
    }
} st[N << 1];
node combine(node lef, node rig) {
    node rs;
    rs.res = lef.res + rig.res;

    if (lef.min < rig.min) {
        rs.min = lef.min;
        rs.min_cnt = lef.min_cnt;
    } else if (lef.min == rig.min) {
        rs.min = lef.min;
        rs.min_cnt = lef.min_cnt + rig.min_cnt;
    } else {
        rs.min = rig.min;
        rs.min_cnt = rig.min_cnt;
    }

    return rs;
}
void down(int i) {
    if ((i << 1) < (N << 1)) st[i << 1].laz += st[i].laz;
    if ((i << 1 | 1) < (N << 1)) st[i << 1 | 1].laz += st[i].laz;
    st[i].laz = 0;
}
void upd(int i) {
    st[i] = combine(st[i << 1], st[i << 1 | 1]);
}
void change(int i, int b, int e) {
    if (!st[i].laz) return;

    if (st[i].min == 0) {
        st[i].res += st[i].min_cnt;
        // write("add", i, b, e, st[i].min_cnt);
    } else if (st[i].min + st[i].laz == 0) {
        st[i].res -= st[i].min_cnt;
        // write("rem", i, b, e, st[i].min_cnt);
    }

    st[i].min += st[i].laz;
    down(i);
}
void push(int i, int b, int e) {
    int m = b + e >> 1;

    down(i);
    change(i << 1, b, m);
    change(i << 1 | 1, m + 1, e);
    upd(i);
}
void mod(int l, int r, int v, int i = 1, int b = 0, int e = N - 1) {
    if (l > e || r < b) return;
    if (l <= b && e <= r) {
        // write("mod", i, l, r, v);
        st[i].laz += v;
        change(i, b, e);
        return;
    }
    push(i, b, e);
    int m = b + e >> 1;
    mod(l, r, v, i << 1, b, m);
    mod(l, r, v, i << 1 | 1, m + 1, e);
    upd(i);
}
void solve() {
    for (int i = 1; i < N + N; ++i)
        st[i].min_cnt = 1 << (__builtin_clz(i) - 16);

    int n;
    cin >> n;
    vvii query(N);
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        query[x1].push_back({y1 + 1, y2});
        query[x2].push_back({-y1 - 1, -y2});
    }
    int res = 0;
    for (int i = 0; i < N; ++i) {
        for (auto& q : query[i]) {
            int l = q.fi, r = q.se, v = 1;
            if (l < 0) {
                l = -l;
                r = -r;
                v = -1;
            }
            // write("mod", i, l, r, v);
            mod(l, r, v);
        }
        res += st[1].res;
        // write("res1", i, st[1].res, st[1].max, st[1].min);
        // write("res2", i, st[2].res, st[2].max, st[2].min);
        // write("res3", i, st[3].res, st[3].max, st[3].min);
    }
    write(res);
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