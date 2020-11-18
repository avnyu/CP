#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define pll pair<ll, ll>
#define dd pair<double, double>
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vii vector<ii>
#define vll vector<pll>
#define vdd vector<dd>
#define vvi vector<vi>
#define vvl vector<vl>
#define vvd vector<vd>
#define vvii vector<vii>
#define vvll vector<vll>
#define vvdd vector<vdd>
#define fi first
#define se second
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int N = 1 << 18;
vi it(N << 1), lz(N << 1);

void push(int i, int l, int r) {
    if (!lz[i] || i >= N) return;
    it[i << 1] ^= lz[i];
    lz[i << 1] ^= lz[i];
    it[i << 1 | 1] ^= lz[i];
    lz[i << 1 | 1] != lz[i];
    lz[i] = 0;
}
void add(int b, int e, int v, int i = 1, int l = 0, int r = N - 1) {
    push(i, l, r);
    if (e < l || b > r) return;
    if (b <= l && r <= e) {
        it[i] ^= v;
        lz[i] ^= v;
        return;
    }
    int m = (l + r) >> 1;
    add(b, e, v, i << 1, l, m);
    add(b, e, v, i << 1 | 1, m + 1, r);
}
int get(int p, int i = 1, int l = 0, int r = N - 1) {
    push(i, l, r);
    if (p > r || p < l) return 0;
    if (l == r) return it[i];
    int m = (l + r) >> 1;
    return get(p, i << 1, l, m) + get(p, i << 1 | 1, m + 1, r);
}
void solve(int T) {
    int n, q;
    cin >> n >> q;
    vi a(32, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        add(i, i, x);
        for (int j = 0; j < 32; ++j)
            if (1 << j & x) a[j]++;
    }
    ll res = 0;
    int p = n;
    for (int i = 0; i < q; ++i) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            for (int j = 0; j < 32; ++j)
                if (1 << j & x) a[j]++;
            add(p, p, x);
            ++p;
            ++n;
        } else if (t == 2) {
            x = get(x - 1);
            for (int j = 0; j < 32; ++j)
                if (1 << j & x) a[j]--;
            --n;
        } else {
            for (int j = 0; j < 32; ++j)
                if (1 << j & x) a[j] = n - a[j];
            add(0, p - 1, x);
        }
        ll res = 0;
        for (int j = 0; j < 32; ++j) res += (1 << j) * a[j];
        cout << res << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int i = 0; i++ < t;) solve(i);

    return 0;
}

void print() { cout << "\n"; }
template <typename T, typename... Args>
void print(T x, Args... args) {
    if (sizeof...(args)) {
        cout << x << ' ';
        print(args...);
    } else {
        cout << x << endl;
    }
}