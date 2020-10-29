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

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

ll n = 10;
vvll jim(n, vll(2));
vvll other(n, vll(3));

bool conflict(ll t, ll w, ll e, ll b, ll& k) {
    k = (t - b) / (w + e) * (w + e) + b;
    k = max(k, b);
    return t >= k && t < k + w;
}
void solve() {
    for (auto& i : jim) cin >> i[0] >> i[1];
    for (auto& i : other) cin >> i[0] >> i[1] >> i[2];
    ll time = 3;

    ll t = 0, cur = 0;
    while (time) {
        ll k;

        if (conflict(t, other[cur][0], other[cur][1], other[cur][2], k))
            t = k + other[cur][0];

        if (t + jim[cur][0] > k + other[cur][0] + other[cur][1] ||
            (k > t && k < t + jim[cur][0]))
            other[cur][2] = t + jim[cur][0];

        t += jim[cur][0] + jim[cur][1];

        if (cur == n - 1) time--;
        cur = (cur + 1) % n;
    }

    print(t - jim[n - 1][1]);
}
int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
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