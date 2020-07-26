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

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

int N;
vi seg, laz;
void push(int i) {
    seg[i << 1] += laz[i];
    laz[i << 1] += laz[i];
    seg[i << 1 | 1] += laz[i];
    laz[i << 1 | 1] += laz[i];
    laz[i] = 0;
}
void upd(int l, int r, int v, int i = 1, int b = 0, int e = N - 1) {
    if (b > r || e < l) return;
    if (l <= b && e <= r) {
        seg[i] += v;
        laz[i] += v;
        return;
    }
    push(i);
    int m = b + e >> 1;
    upd(l, r, v, i << 1, b, m);
    upd(l, r, v, i << 1 | 1, m + 1, e);
}
int get(int p, int i = 1, int b = 0, int e = N - 1) {
    if (b > p || e < p) return 0;
    if (p == b && p == e) return seg[i];
    push(i);
    int m = b + e >> 1;
    return get(p, i << 1, b, m) + get(p, i << 1 | 1, m + 1, e);
}

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    N = n;
    seg.assign(N << 2, 0);
    laz.assign(N << 2, 0);

    for (int i = 0; i < n; ++i)
        if (a[i] == '1') upd(i, i, 1);

    int l = 0, r = n - 1;
    vi res;
    for (int i = n; i--;) {
        if (get(r) % 2 != b[i] - '0') {
            if (get(l) % 2 != get(r) % 2) {
                res.push_back(1);
                upd(l, l, 1);
            }
            res.push_back(i + 1);
            upd(min(l, r), max(l, r), 1);
            swap(l, r);
        }
        r += r > l ? -1 : 1;
    }
    cout << res.size() << " \n"[res.empty()];
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << " \n"[i == res.size() - 1];
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}

void print() { cout << "\n"; }
template <typename T, typename... Args>
void print(T x, Args... args) {
    if (sizeof...(args)) {
        cout << x << ' ';
        print(args...);
    } else {
        cout << x << '\n';
    }
}
