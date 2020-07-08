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

const int N = 1 << 17;
const ll M = 1e18;

struct ST {
    vll st, lz;
    ST() {
        st.resize(N << 1, 0);
        lz.resize(N << 1, 0);
    }
    void push(int i) {
        st[i << 1] += lz[i];
        lz[i << 1] += lz[i];
        st[i << 1 | 1] += lz[i];
        lz[i << 1 | 1] += lz[i];
        lz[i] = 0;
    }
    void update(int i) {
        st[i] = min(st[i << 1], st[i << 1 | 1]);
    }
    void modify(int l, int r, ll v, int i = 1, int b = 0, int e = N - 1) {
        if (l > e || r < b) return;
        if (l <= b && e <= r) {
            st[i] += v;
            lz[i] += v;
            return;
        }
        push(i);
        int m = b + e >> 1;
        modify(l, r, v, i << 1, b, m);
        modify(l, r, v, i << 1 | 1, m + 1, e);
        update(i);
    }
    ll get(int l, int r, int i = 1, int b = 0, int e = N - 1) {
        if (l > e || r < b) return M;
        if (l <= b && e <= r) return st[i];
        push(i);
        int m = b + e >> 1;
        ll res = min(get(l, r, i << 1, b, m), get(l, r, i << 1 | 1, m + 1, e));
        update(i);
        return res;
    }
    void reset() {
        fill(all(st), 0);
        fill(all(lz), 0);
    }
} lef, rig;

void solve() {
    lef.reset();
    rig.reset();

    int n, q;
    cin >> n >> q;

    vll a(n + 1, 0);
    ll sum = 0;

    for (int i = 0; i++ < n;) {
        cin >> a[i];
        lef.modify(i, n, a[i]);
        rig.modify(1, i, a[i]);
        sum += a[i];
    }

    for (int i = 0; i < q; ++i) {
        char c;
        ll s, t;
        cin >> c >> s >> t;

        if (c == 'Q') {
            ll l = lef.get(0, s - 1), r = rig.get(t + 1, n + 1);
            write(sum - l - r);
        } else {
            sum += t - a[s];
            lef.modify(s, n, t - a[s]);
            rig.modify(1, s, t - a[s]);
            a[s] = t;
        }
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();

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