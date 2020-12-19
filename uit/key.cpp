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

struct SA {
    string s;
    int n, lgn;
    vi suf, lcp, rank;
    vvi st;
    void init(string const& str, bool _lcp, bool _st);
    void init_lcp();
    void init_st();
    int lcp_query(int l, int r);
    int lower_bound(string const& x);
    int upper_bound(string const& x);
    bool is_substr(string const& x);
};

int get_char(string& s, int l, int r) {
    int mp = l;
    for (int i = l; i <= r; ++i) {
        if (s[i] < s[mp]) mp = i;
    }
    return mp;
}
ii get_sub(string s, int l, int r, int k) {
    s += ' ';
    SA a;
    a.init(s, 0, 0);
    s += s;
    int mp = 0;
    for (int i = 0; i < a.n; ++i) {
        if (a.suf[i] >= l && a.suf[i] <= r) {
            mp = i;
            break;
        }
    }
    // return ii{a.suf[mp], a.suf[mp] + k - 1};
    // print(a.suf[mp], s.substr(a.suf[mp], k));
    string ms = s.substr(a.suf[mp], k);
    
    int lf = mp;
    int rg = a.upper_bound(ms);

    mp = a.suf[mp];
    for (int i = lf; i < rg; ++i)
        if (a.suf[i] >= l && a.suf[i] <= r) mp = min(mp, a.suf[i]);
    // print(l, r, k, "substr", mp, mp + k - 1);
    return ii{mp, mp + k - 1};
}
void solve(int T) {
    string s;
    int k, n;
    cin >> s >> k;
    n = s.size();

    if (k == 0) {
        return;
    } else if (k == 1) {
        cout << s[get_char(s, 0, n - k)] << '\n';
        return;
    } else if (k == 2) {
        int l = get_char(s, 0, n - k);
        int r = get_char(s, l + 1, n - 1);
        cout << s[l] << s[r] << '\n';
        return;
    }

    int lf = get_char(s, 0, n - k);
    int l, r;
    tie(l, r) = get_sub(s, lf + 1, n - k + 1, k - 2);
    int rg = get_char(s, r + 1, n - 1);

    cout << s[lf];
    for (int i = l; i <= r; ++i) cout << s[i];
    cout << s[rg] << '\n';
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
        cout << x << '\n';
    }
}
void SA::init(string const& str, bool _lcp, bool _st) {
    const int alphabet = 128;
    s = str + str;
    n = s.size() >> 1;
    lgn = 32 - __builtin_clz(n);
    suf.assign(n, 0);
    vi c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++) cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++) cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++) suf[--cnt[s[i]]] = i;
    c[suf[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[suf[i]] != s[suf[i - 1]]) classes++;
        c[suf[i]] = classes - 1;
    }
    vi pn(n), cn(n);
    for (int h = 1; h < n; h <<= 1) {
        for (int i = 0; i < n; i++) {
            pn[i] = suf[i] - h;
            if (pn[i] < 0) pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++) cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++) cnt[i] += cnt[i - 1];
        for (int i = n; i--;) suf[--cnt[c[pn[i]]]] = pn[i];
        cn[suf[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            ii cur = {c[suf[i]], c[(suf[i] + h) % n]};
            ii prev = {c[suf[i - 1]], c[(suf[i - 1] + h) % n]};
            if (cur != prev) ++classes;
            cn[suf[i]] = classes - 1;
        }
        c.swap(cn);
    }

    if (_lcp) init_lcp();
    if (_lcp && _st) init_st();
}
void SA::init_lcp() {
    int k = 0;
    rank.assign(n, 0);
    lcp.assign(n, 0);
    for (int i = 0; i < n; ++i) rank[suf[i]] = i;
    for (int i = 0; i < n; ++i) {
        int j = suf[(rank[i] + 1) % n];
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) ++k;
        lcp[rank[i]] = k;
        if (k) --k;
    }
}
void SA::init_st() {
    st.assign(n, vi(lgn, -1));
    for (int i = 0; i < n; ++i) st[i][0] = lcp[i];
    for (int j = 1; j < lgn; ++j)
        for (int i = 0; i < n - (1 << j); ++i)
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}
int SA::lower_bound(string const& x) {
    int k = x.size(), res = n, add = 1 << lgn;
    while (add) {
        if (res - add >= 0 && s.compare(suf[res - add], k, x) >= 0) res -= add;
        add >>= 1;
    }
    return res;
}
int SA::upper_bound(string const& x) {
    int k = x.size(), res = n, add = 1 << lgn;
    while (add) {
        if (res - add >= 0 && s.compare(suf[res - add], k, x) > 0) res -= add;
        add >>= 1;
    }
    return res;
}
bool SA::is_substr(string const& x) {
    int p = lower_bound(x), k = x.size();
    if (p == n) return false;
    return s.compare(p, k, x) == 0;
}
int SA::lcp_query(int l, int r) {
    if (l == r) return n;
    int j = 31 - __builtin_clz(r - l);
    return min(st[l][j], st[r - (1 << j)][j]);
}