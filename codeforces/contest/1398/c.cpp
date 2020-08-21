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

const int M = 1e6;
vi cnt(M + M, 0);

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (auto& i : a) {
        char c;
        cin >> c;
        i = c - '0';
    }
    vi c = a;
    for (int i = 1; i < n; ++i) a[i] += a[i - 1];

    vi b(n);
    iota(all(b), 1);

    for (int i = 0; i < n; ++i) cnt[M + a[i] - b[i]]++;

    ll ans = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        ans += cnt[M + sum];
        sum += c[i] - 1;
        cnt[M + a[i] - b[i]]--;
    }
    print(ans);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
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