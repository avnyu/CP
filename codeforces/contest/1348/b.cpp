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
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (auto& i : a) cin >> i;
    vi cnt(n + 1);
    vi pos(n);
    int p = 0;
    for (auto& i : a) {
        if (cnt[i] == 0) {
            pos[p++] = i;
            cnt[i] = 1;
        }
    }
    if (p > k) {
        write(-1);
        return;
    }
    vi x;
    for (int i = 0; i < k; ++i) x.push_back(pos[i % p]);
    write(x.size() * n);

    for (int i = 0; i < n; ++i)
        for (auto& j : x) cout << j << ' ';

    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}
template <typename T, typename... Args>
void write(T x, Args... args) {
    cout << x;
    if (sizeof...(args)) {
        cout << ' ';
        write(args...);
    } else
        cout << '\n';
}