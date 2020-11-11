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
#define what_is(x) cerr << #x << endl;

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int N = 50;
int n;
vl c(N);
vector<map<ll, ll>> cnt(N);

ll dp(ll p, ll x) {
    if (p == n) return 1;
    if (cnt[p].find(x) != cnt[p].end()) return cnt[p][x];

    cnt[p][x] = dp(p + 1, x / c[p]);
    if (x % c[p]) cnt[p][x] += dp(p + 1, x / c[p] + 1);
    return cnt[p][x];
}
void solve(int T) {
    ll x;
    cin >> n >> x;
    vl a(n + 1);
    for (int i = 0; i < n; ++i) cin >> a[i];
    a[n] = a[n - 1];
    for (int i = 0; i < n; ++i) c[i] = a[i + 1] / a[i];

    print(dp(0, x));
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