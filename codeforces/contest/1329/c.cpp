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

const int N = 20;
int n, m;
vi a(1 << N + 1), h(1 << N), res;

void del(int i) {
    if (a[i << 1] == 0 && a[i << 1 | 1] == 0) {
        a[i] = 0;
        return;
    } else if (a[i << 1] > a[i << 1 | 1]) {
        a[i] = a[i << 1];
        del(i << 1);
    } else {
        a[i] = a[i << 1 | 1];
        del(i << 1 | 1);
    }
}
bool test(int i) {
    while (h[i] < m) i = a[i << 1] > a[i << 1 | 1] ? i << 1 : i << 1 | 1;
    return a[i << 1] + a[i << 1 | 1];
}
void dfs(int i) {
    if (!a[i]) return;
    while (test(i)) {
        res.push_back(i);
        del(i);
    }
    dfs(i << 1);
    dfs(i << 1 | 1);
}
ll sum(int i) {
    if (!a[i]) return 0;
    return sum(i << 1) + sum(i << 1 | 1) + a[i];
}
void solve() {
    res.clear();
    cin >> n >> m;
    for (int i = 1; i < 1 << n; ++i) h[i] = h[i >> 1] + 1;
    for (int i = 1; i < 1 << n; ++i) cin >> a[i];
    dfs(1);
    write(sum(1));
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << " \n"[i == res.size() - 1];
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