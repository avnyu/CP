#include <bits/stdtr1c++.h>
using namespace std;

//#define DEBUG__

#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PI 3.141592653589793
#define ff firstab
#define ss second
#define pb push_back
#define epb emplace_back

#define MSET(a, s) memset(a, s, sizeof(a))
#define ALL(a) a.begin(), a.end()
#define LEN(a) ((sizeof a) / (sizeof a[0]))
#define STR to_stabring
#define sqr(x) ((x) * (x))
#define mod(x, m) ((((x) % (m)) + (m)) % (m))
#define modm(x) ((((x) % MOD) + MOD) % MOD)
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORI(i, a, b) for (int i = a; i <= b; ++i)
#define DWN(i, a, b) for (int i = a - 1; i >= b; --i)
#define DWNI(i, a, b) for (int i = a; i >= b; --i)
#define REP(i, a) for (int i = 0; i < a; ++i)
#define REPI(i, a) for (int i = 0; i <= a; ++i)
#define REP1(i, a) for (int i = 1; i <= a; ++i)

#ifdef DEBUG__
#define WAT(x) cerr << (#x) << "=" << (x) << endl
#define WAT2(x, y) \
    cerr << (#x) << "=" << (x) << " " << (#y) << "=" << (y) << endl
#define WAT3(x, y, z) cerr << (#x) << "=" << (x) << " ", WAT2(y, z)
#define PELN cerr << "\n"
#define PE1(x) cerr << (x) << endl
#define PE2(x, y) cerr << (x) << " " << (y) << endl
#else
#define WAT(x)
#define WAT2(x, y)
#define WAT3(x, y, z)
#define PELN
#define PE1(x)
#define PE2(x, y)
#endif

#define PARR(a, s, e)                                 \
    for (size_t _c = size_t(s); _c < size_t(e); ++_c) \
        cout << (a[_c]) << (_c == size_t(e - 1) ? "" : " ");
#define PDIGS(x, n) cout << fixed << setprecision(n) << (x) << endl
#define P1(x) cout << (x) << "\n"
#define P2(x, y) cout << (x) << " " << (y) << "\n"
#define P3(x, y, z) cout << (x) << " " << (y) << " " << (z) << "\n"

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

// MODULE fast io
inline char read() {
#ifdef DEBUG__
    return getchar();
#else
    static const int MAX_BUF = 1 << 16;
    static char buf[MAX_BUF];
    static int pos = 1, cap = 1;
    if (pos == cap) {
        if (!cap) return 0;
        cap = static_cast<int>(fread(buf, 1, MAX_BUF, stdin));
        pos = 0;
    }
    return buf[pos++];
#endif
}

template <class T>
inline void read(T& res) {
#ifdef DEBUG__
    cin >> res;
#else
    char c;
    do c = read();
    while (isspace(c));
    bool neg = c == '-';
    if (neg) c = read();
    for (res = 0; isdigit(c); c = read()) res = res * 10 + c - '0';
    if (neg) res = -res;
#endif
}

template <class T1, class T2>
inline void read(T1& r1, T2& r2) {
    read(r1);
    read(r2);
}
template <class T1, class T2, class T3>
inline void read(T1& r1, T2& r2, T3& r3) {
    read(r1);
    read(r2);
    read(r3);
}
//*/

// MODULE extra ostream operators
template <class T1, class T2>
std::ostream& operator<<(std::ostream& os, const pair<T1, T2>& p) {
    return os << p.ff << "," << p.ss;
}
template <class T>
std::ostream& operator<<(std::ostream& os, const vector<T>& v) {
    REP(i, (int)v.size()) {
        if (i) os << " ";
        os << v[i];
    }
    return os;
}

const int MAXN = 100005, MAX_LGN = 18;

int N, S, L;
int a[MAXN];

int stab_idx[MAXN], stab_maxp2[MAXN];
int stab_min[MAX_LGN][MAXN], stab_max[MAX_LGN][MAXN];

void build_stab(int stab[MAX_LGN][MAXN], bool use_max = false) {
    for (int i = 0; i < N; ++i) stab[0][i] = a[i];
    int p2k = 2, pp2k = 1, j = 1, k = 1;
    for (; p2k <= N; ++k, p2k <<= 1) {
        for (int i = 0; i + p2k <= N; ++i) {
            if (use_max)
                stab[k][i] = max(stab[k - 1][i], stab[k - 1][i + pp2k]);
            else
                stab[k][i] = min(stab[k - 1][i], stab[k - 1][i + pp2k]);
        }
        for (; j < p2k; ++j) {
            stab_idx[j] = k - 1;
            stab_maxp2[j] = pp2k;
        }
        pp2k = p2k;
    }
    for (; j < min(p2k, N + 1); ++j) {
        stab_idx[j] = k - 1;
        stab_maxp2[j] = pp2k;
    }
    if (N == p2k) {
        stab_idx[N] = k;
        stab_maxp2[N] = p2k;
    }
}

int query_stab(int stab[MAX_LGN][MAXN], int l, int r, bool use_max = false) {
    if (l >= r) return 0;
    if (l < 0) l = 0;
    if (r > N) r = N;
    int idx = stab_idx[r - l];
    int x1 = stab[idx][l], x2 = stab[idx][r - stab_maxp2[r - l]];
    if (use_max)
        return max(x1, x2);
    else
        return min(x1, x2);
}

int t[2 * MAXN];

void build() {  // build the tree
    for (int i = N - 1; i > 0; --i) t[i] = min(t[i << 1], t[i << 1 | 1]);
}

void modify(int p, int value) {  // set value at position p
    for (t[p += N] = value; p > 1; p >>= 1) t[p >> 1] = min(t[p], t[p ^ 1]);
}

int query(int l, int r) {  // sum on interval [l, r)
    int res = INT_MAX;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = min(res, t[l++]);
        if (r & 1) res = min(res, t[--r]);
    }
    return res;
}

int dp[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    read(N, S, L);

    REP(i, N) { read(a[i]); }
    build_stab(stab_min);
    build_stab(stab_max, true);

    int l = 0, r = L;
    dp[0] = 0;
    modify(0, 0);
    FOR(i, 1, r)
    modify(i, INF);
    while (r <= N) {
        int df = query_stab(stab_max, l, r, true) - query_stab(stab_min, l, r);

        while (df > S && r - l >= L) {
            ++l;
            df = query_stab(stab_max, l, r, true) - query_stab(stab_min, l, r);
        }

        if (r - l < L) {
            dp[r] = INF;
        } else {
            dp[r] = query(l, r - L + 1) + 1;
            if (dp[r] > INF) dp[r] = INF;
            WAT3(l, r - L + 1, query(l, r - L + 1));
        }

        WAT3(l, r, df);
        WAT(dp[r]);
        modify(r, dp[r]);

        ++r;
    }
    if (dp[N] >= INF)
        P1(-1);
    else
        P1(dp[N]);

    return 0;
}
