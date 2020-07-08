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

using namespace std;

void write();
template <typename T, typename... Args>
void write(T x, Args... args);

void solve() {
    const int M = 998244353;
    int n, k;
    cin >> n >> k;
    vii p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].fi;
        p[i].se = i;
    }
    sort(rall(p));
    p.erase(p.begin() + k, p.end());
    sort(all(p), [](ii& a, ii& b) { return a.se < b.se; });
    ll sum = 0, num = 1;
    for (int i = 0; i < k; ++i) sum += p[i].fi;
    for (int i = 1; i < k; ++i) num = num * (p[i].se - p[i - 1].se) % M;
    write(sum, num);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
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