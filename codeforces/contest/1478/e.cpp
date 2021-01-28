#include <bits/stdc++.h>

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
#define prt(v) \
    for (auto& i : v) cout << i << " \n"[&i == &v.back()]

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int N = 1 << 19;
vi it(N << 1), lz(N << 1), ord(N << 1);

void push(int i, int l, int r) {
    if (ord[i] == -1) return;
    int m = (l + r) >> 1;

    if (ord[i] > ord[i << 1]) {
        it[i << 1] = lz[i] * (m - l + 1);
        lz[i << 1] = lz[i];
        ord[i << 1] = ord[i];
    }

    if (ord[i] > ord[i << 1 | 1]) {
        it[i << 1 | 1] = lz[i] * (r - m);
        lz[i << 1 | 1] = lz[i];
        ord[i << 1 | 1] = ord[i];
    }

    ord[i] = -1;
}
void upd(int i) { it[i] = it[i << 1] + it[i << 1 | 1]; }
void mod(int b, int e, int v, int stt, int i = 1, int l = 0, int r = N - 1) {
    if (r < b || l > e) return;
    if (b <= l && r <= e) {
        it[i] = v * (r - l + 1);
        lz[i] = v;
        ord[i] = stt;
        return;
    }
    push(i, l, r);
    int m = (l + r) >> 1;
    mod(b, e, v, stt, i << 1, l, m);
    mod(b, e, v, stt, i << 1 | 1, m + 1, r);
    upd(i);
}
int get(int b, int e, int i = 1, int l = 0, int r = N - 1) {
    if (r < b || l > e) return 0;
    if (b <= l && r <= e) return it[i];
    push(i, l, r);
    int m = (l + r) >> 1;
    m = get(b, e, i << 1, l, m) + get(b, e, i << 1 | 1, m + 1, r);
    upd(i);
    return m;
}

void solve(int T) {
    int n, q;
    string s, f;
    cin >> n >> q >> s >> f;
    vi l(q), r(q);
    for (int i = 0; i < q; ++i) {
        cin >> l[i] >> r[i];
        l[i]--;
        r[i]--;
    }

    bool ok = true;

    fill(ord.begin(), ord.begin() + (n << 2), -1);
    int stt = 0;

    for (int i = 0; i < n; ++i) mod(i, i, f[i] - '0', stt++, 1, 0, n - 1);

    for (int i = q, t, x; i--;) {
        t = get(l[i], r[i], 1, 0, n - 1);
        x = r[i] - l[i] + 1;
        if (t + t == x)
            ok = false;
        else if (t + t > x) {
            mod(l[i], r[i], 1, stt++, 1, 0, n - 1);
        } else {
            mod(l[i], r[i], 0, stt++, 1, 0, n - 1);
        }
    }

    for (int i = 0; i < n; ++i) f[i] = char('0' + get(i, i, 1, 0, n - 1));

    ok &= (f == s);

    print(ok ? "YES" : "NO");
    // print(f, s);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    cin >> t;
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
        cout << x << '\n';
    }
}