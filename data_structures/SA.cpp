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
#define debug(x) cerr << #x << ' ' << x << '\n'

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

struct SA {
    int n;
    string s;
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
int lowest(int l, int r, SA& sfa) {
    int res = sfa.rank[l], add = 1 << 30, len = r - l + 1;
    while (add) {
        if (res - add >= 0 && sfa.lcp_query(res - add, res) >= len) res -= add;
        add >>= 1;
    }
    return res;
}
void solve() {
    string s;
    SA a;
    int n;

    cin >> s;
    n = s.size();
    s.push_back(char(32));
    a.init(s, 1, 1);
    s += s;

    ll res = 1LL * n * (n + 1) >> 1;
    for (auto& i : a.st)
        for (auto& j : i) res += max(0, j);

    print(res);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
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
        cout << x << endl;
    }
}
void SA::init(string const& str, bool _lcp, bool _st) {
    const int alphabet = 128;
    s = str + str;
    n = s.size() >> 1;
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
    const int lgn = 32 - __builtin_clz(n);
    st.assign(n, vi(lgn, -1));
    for (int i = 0; i < n; ++i) st[i][0] = lcp[i];
    for (int j = 1; j < lgn; ++j)
        for (int i = 0; i < n - (1 << j); ++i)
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}
int SA::lower_bound(string const& x) {
    int k = x.size(), res = n, add = 1 << 30;
    while (add) {
        if (res - add >= 0 && x <= s.substr(suf[res - add], k)) res -= add;
        add >>= 1;
    }
    return res;
}
int SA::upper_bound(string const& x) {
    int k = x.size(), res = n, add = 1 << 30;
    while (add) {
        if (res - add >= 0 && x < s.substr(suf[res - add], k)) res -= add;
        add >>= 1;
    }
    return res;
}
bool SA::is_substr(string const& x) {
    int p = lower_bound(x), k = x.size();
    if (p == n) return false;
    for (int i = 0; i < k; ++i)
        if (s[suf[p] + i] != x[i]) return false;
    return true;
}
int SA::lcp_query(int l, int r) {
    if (l == r) return n;
    int j = 31 - __builtin_clz(r - l);
    return min(st[l][j], st[r - (1 << j)][j]);
}