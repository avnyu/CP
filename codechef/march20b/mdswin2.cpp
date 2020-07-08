#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
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
#define iiii tuple<int64_t, int, int, int>

using namespace std;

void write();
template <typename T, typename... Args>
void write(T x, Args... args);
template <typename T>
void print_all(vector<T>& a);

const int M = 998244353;
const int N = 1e5 + 1;

int n, m, q;
int a[N], res[N], siz[N], cnt[N];
vll fac(N, 1);
vector<iiii> query(N);
bitset<N> in;

int readInt() {
    int A;
    bool K;
    char C;
    C = A = K = 0;
    while (C < '0' || C > '9') K |= C == '-', C = getchar();
    while (C > '/' && C < ':')
        A = (A << 3) + (A << 1) + (C ^ 48), C = getchar();
    return (K ? -A : A);
}
void writeInt(int X) {
    if (X < 0) putchar('-'), X = -X;
    if (X > 9) write(X / 10);
    putchar(X % 10 | 48);
}
void init() {
    for (int i = 1; i < N; ++i) fac[i] = fac[i - 1] * i % M;
}
ll fpow(ll b, ll e) {
    ll res = 1;
    while (e) {
        if (e & 1) res = res * b % M;
        e >>= 1;
        b = b * b % M;
    }
    return res;
}
ll gcdex(ll b) { return fpow(b, M - 2); }

ll C(ll k, ll e) {
    if (k > e || k < 0 || e < 0) return 0;
    return fac[e] * gcdex(fac[k]) % M * gcdex(fac[e - k]) % M;
}
void normalize() {
    int b[] = (a, a + n);
    sort(all(b));
    uni(b);
    for (auto& i : a) i = lower_bound(all(b), i) - b.begin();
    m = b.size();
}
void add(int& t, int& nim) {
    nim ^= t;
    cnt[t]--;
    if (!cnt[t]) in.reset(t);

    t++;

    if (!cnt[t]) in.set(t);

    cnt[t]++;
    nim ^= t;
}
void rem(int& t, int& nim) {
    nim ^= t;
    cnt[t]--;
    if (!cnt[t]) in.reset(t);

    t--;

    if (!cnt[t]) in.set(t);
    cnt[t]++;
    nim ^= t;
}
inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) { return 0; }
    int hpow = 1 << (pow - 1);
    int seg = (x < hpow) ? ((y < hpow) ? 0 : 3) : ((y < hpow) ? 1 : 2);
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquaresiz = int64_t(1) << (2 * pow - 2);
    int64_t ans = seg * subSquaresiz;
    int64_t add = gilbertOrder(nx, ny, pow - 1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquaresiz - add - 1);
    return ans;
}

void solve() {
    n = readInt();
    for (int i = 0; i < n; ++i) a[i] = readInt();
    normalize();

    q = readInt();
    for (int i = 0; i < q; ++i) {
        int l = readInt(), r = readInt();
        int64_t o;
        o = gilbertOrder(l, r, 20, 0);
        query[i] = {o, l - 1, r, i};
    }
    sort(query.begin(), query.begin() + q);

    fill(all(siz), 0);
    fill(all(cnt), 0);
    fill(all(res), 0);

    int xl = 0, xr = 0;
    cnt[0] = m + 1;
    in.reset();

    int pl = 0, pr = 0, nim = 0;

    for (int j = 0; j < q; ++j) {
        int l, r, p;
        int64_t o;
        tie(o, l, r, p) = query[j];

        for (int i = l; i < pl; ++i) add(siz[a[i]], nim);
        for (int i = pr; i < r; ++i) add(siz[a[i]], nim);

        for (int i = pl; i < l; ++i) rem(siz[a[i]], nim);
        for (int i = r; i < pr; ++i) rem(siz[a[i]], nim);

        for (int f = in._Find_first(); f < 100001; f = in._Find_next(f))
            res[p] = (res[p] + C(f ^ nim, f) * cnt[f] % M) % M;

        if (!nim) res[p] = 0;

        pl = l, pr = r;
    }

    for (int i = 0; i < q; ++i) cout << res[i] << "\n";
}

int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    // clock_t st = clock();

    init();

    int t = 1;
    cin >> t;
    while (t--) solve();

    // write("time", clock() - st);

    return 0;
}

void write() { cout << "\n"; }
template <typename T, typename... Args>
void write(T x, Args... args) {
    cout << x << ' ';
    write(args...);
}
template <typename T>
void print_all(vector<T>& a) {
    for (int i = 0; i < a.siz(); ++i) cout << a[i] << " \n"[i == a.siz() - 1];
}