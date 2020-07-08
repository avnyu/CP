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
#define what_is(x) cerr << #x << " is " << x << endl;
#define iii tuple<int, int, int>

using namespace std;

void write();
template <typename T, typename... Args>
void write(T x, Args... args);

const int N = 3e5 + 1;
vi ft(N);

void upd(int p, int v) {
    for (; p < N; p += p & -p) ft[p] += v;
}
int get(int p) {
    int res = 0;
    for (; p; p -= p & -p) res += ft[p];
    return res;
}

void solve() {
    int n;
    cin >> n;
    vi p(n), q(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    for (int i = 0; i < n; ++i) cin >> q[i];

    vii a(n);
    for (int i = 0; i < n; ++i) a[i].fi = p[i], a[i].se = i + 1;
    sort(rall(a));

    vi res(n);
    int mx = n;
    set<iii> s;
    for (int i = 0; i < n; ++i) {
        // add
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}

void write() {
    cout << "\n";
}
template <typename T, typename... Args>
void write(T x, Args... args) {
    cout << x << ' ';
    write(args...);
}