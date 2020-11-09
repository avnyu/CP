#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define pll pair<ll, ll>
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

const int M = 1e9 + 7;

void rem(set<ii>& s, int p, multiset<int, greater<int>>& l) {
    auto t = --s.upper_bound(ii{p, M});
    int lef = t->fi, rig = t->se;

    s.erase(t);
    l.erase(l.find(rig - lef + 1));

    if (lef < p) {
        s.insert(ii{lef, p - 1});
        l.insert(p - lef);
    }
    if (rig > p) {
        s.insert(ii{p + 1, rig});
        l.insert(rig - p);
    }
}
void add(set<ii>& s, int p, multiset<int, greater<int>>& l) {
    auto v = s.upper_bound(ii{p, M});

    int lef = p, rig = p;

    if (v != s.begin()) {
        auto u = v;
        --u;

        if (u->se == p - 1) {
            lef = u->fi;

            l.erase(l.find(u->se - u->fi + 1));
            s.erase(u);
        }
    }
    if (v != s.end() && v->fi == p + 1) {
        rig = v->se;

        l.erase(l.find(v->se - v->fi + 1));
        s.erase(v);
    }

    l.insert(rig - lef + 1);
    s.insert(ii{lef, rig});
}
void solve() {
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; ++i) a[i] = i & 1;

    set<ii> black, white;
    multiset<int, greater<int>> len;
    for (int i = 0; i < n; ++i) {
        if (i & 1)
            black.insert(ii{i, i});
        else
            white.insert(ii{i, i});
        len.insert(1);
    }

    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        x--;
        if (a[x]) {
            a[x] = 0;
            rem(black, x, len);
            add(white, x, len);
        } else {
            a[x] = 1;
            rem(white, x, len);
            add(black, x, len);
        }
        print(*len.begin());
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

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