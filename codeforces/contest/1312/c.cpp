#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
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
    ll n, k;
    cin >> n >> k;
    vll a(n);
    priority_queue<ll> q;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        if (x) q.push(x);
    }

    ll j = 0, t = 1;
    while (t <= (ll)1e16) {
        j++;
        t *= k;
    }
    for (; j-- && !q.empty();) {
        t /= k;
        // write(j, t);
        ll x = q.top();
        q.pop();
        if (x >= t) x -= t;
        if (x) q.push(x);
    }

    cout << (q.empty() ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}

void write() { cout << "\n"; }
template <typename T, typename... Args>
void write(T x, Args... args) {
    cout << x << ' ';
    write(args...);
}