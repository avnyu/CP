#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define iiii tuple<int, int, int, int>
#define vi vector<int>
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

using namespace std;

void write();
template <typename T, typename... Args>
void write(T x, Args... args);
template <typename T>
void print_all(vector<T>& a);

const int N = 2e8 + 2;
const int M = 1e8 + 1;
unordered_map<int, pair<ll, ll>> sum;

void add(int p) {
    for (int q = p; q < N; q += q & -q) {
        sum[q].fi++;
        sum[q].se += p;
    }
}
pair<ll, ll> get(int p) {
    pair<ll, ll> res;
    for (; p; p -= p & -p) {
        res.fi += sum[p].fi;
        res.se += sum[p].se;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<ii> p(n);
    vi coor;
    for (auto& i : p) {
        cin >> i.fi;
        i.fi += M;
    }
    for (auto& i : p) cin >> i.se;

    sort(all(p), [](ii& x, ii& y) {
        return x.se < y.se || (x.se == y.se && x.fi < y.fi);
    });

    ll res = 0;
    for (auto& i : p) {
        auto tmp = get(i.fi);
        res += tmp.fi * i.fi - tmp.se;
        add(i.fi);
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

void write() { cout << "\n"; }
template <typename T, typename... Args>
void write(T x, Args... args) {
    cout << x << ' ';
    write(args...);
}
template <typename T>
void print_all(vector<T>& a) {
    for (auto i = a.begin(); i != a.end();) cout << *i << " \n"[++i == a.end()];
}