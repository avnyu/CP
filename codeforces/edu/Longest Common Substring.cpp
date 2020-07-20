#include <bits/stdc++.h>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
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

struct SArr {
    int n;
    string s;
    vi suf, lcp;
    void init(string const& str);
    void init_suf();
    void init_lcp();
    int lower_bound(string const& x);
    int upper_bound(string const& x);
    bool is_substr(string const& x);
};
void solve() {
    string s, t;
    cin >> s >> t;
    int sep = s.size();

    s = s + '!' + t + '@';
    SArr sfa;
    sfa.init(s);
    sfa.init_lcp();

    int pos = -1, len = -1;

    for (int i = 0; i < sfa.n - 1; ++i)
        if ((sfa.suf[i] < sep && sfa.suf[i + 1] > sep) ||
            (sfa.suf[i] > sep && sfa.suf[i + 1] < sep))
            if (sfa.lcp[i] > len) {
                len = sfa.lcp[i];
                pos = sfa.suf[i];
            }
    print(sfa.s.substr(pos, len));
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
        cout << x << '\n';
    }
}
void SArr::init(string const& str) {
    s = str;
    n = s.size();
    init_suf();
}
void SArr::init_suf() {
    const int alphabet = 128;
    suf.resize(n);
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
}
void SArr::init_lcp() {
    vi rank(n);
    lcp.resize(n);
    for (int i = 0; i < n; ++i) rank[suf[i]] = i;

    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = suf[rank[i] + 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) ++k;
        lcp[rank[i]] = k;
        if (k) --k;
    }
}
int SArr::lower_bound(string const& x) {
    int l = 0, r = n - 1, k = x.size(), res = n;

    while (l <= r) {
        int m = l + r >> 1;

        int test = 1;
        for (int i = 0; i < k; ++i) {
            if (s[(suf[m] + i) % n] == x[i]) continue;
            if (s[(suf[m] + i) % n] < x[i])
                test = 0;
            else
                test = 2;
            break;
        }

        if (test == 0) {
            l = m + 1;
        } else {
            res = m;
            r = m - 1;
        }
    }
    return res;
}
int SArr::upper_bound(string const& x) {
    int l = 0, r = n - 1, k = x.size(), res = n;

    while (l <= r) {
        int m = l + r >> 1;

        int test = 1;
        for (int i = 0; i < k; ++i) {
            if (s[(suf[m] + i) % n] == x[i]) continue;
            if (s[(suf[m] + i) % n] < x[i])
                test = 0;
            else
                test = 2;
            break;
        }

        if (test < 2) {
            l = m + 1;
        } else {
            res = m;
            r = m - 1;
        }
    }
    return res;
}
bool SArr::is_substr(string const& x) {
    int p = lower_bound(x), k = x.size();
    if (p == n) return false;
    for (int i = 0; i < k; ++i)
        if (s[(suf[p] + i) % n] != x[i]) return false;
    return true;
}