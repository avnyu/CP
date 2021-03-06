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
    string s;
    cin >> s;
    s += ' ';
    SA a(s, 1, 1);
    s += s;

    // for (int i = 0; i < a.n; ++i) print(i, s.substr(a.suf[i], a.n));
    // for (int i = 0; i < a.n; ++i) cout << i << " \n"[i == a.n - 1];
    // for (int i = 0; i < a.n; ++i) cout << a.lcp[i] << " \n"[i == a.n - 1];

    const int N = 4e5 + 7;
    vii st(N);
    int sn = 0;

    ll res = 1LL * a.n * (a.n - 1) / 2;
    for (int i = 0; i < a.n; ++i) {
        int cur = -1, pos = i;
        if (sn && st[sn - 1].se > a.lcp[i]) {
            cur = st[sn - 1].se;
            pos = st[sn - 1].fi;
            --sn;
        }

        while (cur != -1 && sn && st[sn - 1].se >= a.lcp[i]) {
            res += 1LL * (cur - st[sn - 1].se) * (i - pos) * (i - pos + 1) / 2;
            // print("at", i, "h", st[sn - 1].se + 1, cur, "l", pos, i - 1);
            cur = st[sn - 1].se;
            pos = st[sn - 1].fi;
            --sn;
        }
        res += 1LL * (cur - a.lcp[i]) * (i - pos) * (i - pos + 1) / 2;

        if (!sn || st[sn - 1].se < a.lcp[i]) {
            st[sn++] = {pos, a.lcp[i]};
            // print("add", sn - 1, pos, a.lcp[i]);
        }
    }

    cout << res << '\n';
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