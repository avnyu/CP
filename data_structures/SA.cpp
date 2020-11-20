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
#define prt(u) \
    for (auto& i : u) cout << i << " \n"[&i == &u.back()];

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

struct SA {
    string s;
    int n, lgn;
    vi suf, lcp, rank;
    vvi st;
    SA(string const& str, bool _lcp, bool _st) {
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
    void init_lcp() {
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
    void init_st() {
        st.assign(n, vi(lgn, -1));
        for (int i = 0; i < n; ++i) st[i][0] = lcp[i];
        for (int j = 1; j < lgn; ++j)
            for (int i = 0; i < n - (1 << j); ++i)
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
    int lcp_query(int l, int r) {
        if (l == r) return n;
        int j = 31 - __builtin_clz(r - l);
        return min(st[l][j], st[r - (1 << j)][j]);
    }
    int lower_bound(string const& x) {
        int k = x.size(), res = n, add = 1 << lgn;
        while (add) {
            if (res - add >= 0 && s.compare(suf[res - add], k, x) >= 0)
                res -= add;
            add >>= 1;
        }
        return res;
    }
    int upper_bound(string const& x) {
        int k = x.size(), res = n, add = 1 << lgn;
        while (add) {
            if (res - add >= 0 && s.compare(suf[res - add], k, x) > 0)
                res -= add;
            add >>= 1;
        }
        return res;
    }
    bool is_substr(string const& x) {
        int p = lower_bound(x), k = x.size();
        if (p == n) return false;
        return s.compare(p, k, x) == 0;
    }
};
void solve() {
    string s = "";

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s += char('a' + x - 1);
    }

    s += '!';
    SA a(s, 1, 1);
    s += s;

    // for (int i = 0; i < a.n; ++i) print(i, s.substr(a.suf[i], a.n));
    // for (int i = 0; i < a.n; ++i) cout << i << " \n"[i == a.n - 1];
    // for (int i = 0; i < a.n; ++i) cout << a.lcp[i] << " \n"[i == a.n - 1];

    const int M = 1e9 + 7;

    n = a.lcp.size();
    vi b = a.lcp;
    b.insert(b.begin(), -1);
    b.push_back(-1);

    int stn = 0;
    vi l(n + 2), r(n + 2), st(n + 2);
    st[stn++] = 0;

    for (int i = 0; i++ < n;) {
        while (b[i] <= b[st[stn - 1]]) stn--;
        l[i] = st[stn - 1];
        st[stn++] = i;
    }

    stn = 0;
    st[stn++] = n + 1;
    for (int i = n; i; i--) {
        while (b[i] <= b[st[stn - 1]]) stn--;
        r[i] = st[stn - 1];
        st[stn++] = i;
    }

    // print(s);
    // prt(b);
    // prt(l);
    // prt(r);

    ll res = n - 1, len = n - 1, pos = 0;
    for (int i = 0; i++ < n;) {
        ll cur = 1LL * b[i] * (r[i] - l[i]);
        if (cur > res) {
            res = cur;
            len = b[i];
            pos = a.suf[i - 1];
        }
    }

    cout << res << '\n';
    cout << len << '\n';
    // cout << s.substr(pos, len) << '\n';
    for (int i = 0; i < len; ++i)
        cout << a.s[pos + i] - 'a' + 1 << " \n"[i == len - 1];

    // print(res, len, a.suf[pos - 1]);
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