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

void solve() {
    int n;
    cin >> n;
    int N = n + 7;
    vi a(n);
    vi pos(N, -1);
    vi ans(N, -1);
    vi res(n + 1, N);

    for (auto& i : a) cin >> i;

    for (int i = 0; i < n; ++i) {
        ans[a[i]] = max(ans[a[i]], i - pos[a[i]]);
        pos[a[i]] = i;
    }

    for (int i = 0; i < N; ++i) {
        if (ans[i] == -1) continue;
        ans[i] = max(ans[i], n - pos[i]);
    }

    for (int i = 0; i < N; ++i)
        if (ans[i] != -1) res[ans[i]] = min(res[ans[i]], i);

    for (int i = 0; i++ < n;) res[i] = min(res[i], res[i - 1]);

    for (int i = 0; i++ < n;)
        cout << (res[i] == N ? -1 : res[i]) << " \n"[i == n];
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