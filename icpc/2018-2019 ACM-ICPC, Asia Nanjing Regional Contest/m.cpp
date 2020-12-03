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
#define prt(vec) for(auto&ele:vec)cout<<ele<<" \n"[&ele == &vec.back()]
#define ub(vec, u) upper_bound(vec.begin(), vec.end(), u) - vec.begin()
#define viii vector<tuple<int, int, int>>

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

struct SA {
    string s;
    int n, lgn;
    vi suf, lcp, rank;
    vvi st;
    SA(string const& str, bool _lcp = true, bool _st = true) {
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


vvi manacher(string s) {
    int n = s.size(), m;
    vvi d(2, vi(n, 0));
    m = 0;
    for (int i = 0; i < n; ++i) {
        d[0][i] = m + d[0][m] > i ? min(d[0][m + m - i], m + d[0][m] - i) : 0;
        while (i - d[0][i] - 1 >= 0 && i + d[0][i] + 1 < n && s[i - d[0][i] - 1] == s[i + d[0][i] + 1]) d[0][i]++;
        if (i + d[0][i] > m + d[0][m]) m = i;
    }
    m = 0;
    for (int i = 0; i < n; ++i) {
        d[1][i] = m + d[1][m] > i ? min(d[1][m + m - i - 1], m + d[1][m] - i) : 0;
        while (i - d[1][i] - 1 >= 0 && i + d[1][i] < n && s[i - d[1][i] - 1] == s[i + d[1][i]]) d[1][i]++;
        if (i + d[1][i] > m + d[1][m]) m = i;
    }
    return d;
}
vi kmp(string s) {
    int n = (int)s.length();
    vi pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
void solve(int T) {
	string s, t;
	cin >> s >> t;
	
	s += t;
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
