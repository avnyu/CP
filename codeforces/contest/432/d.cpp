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

const int N = 1e5 + 1;
vi ft(N);

void upd(int p) {
    for (; p < N; p += p & -p) ft[p]++;
}
int get(int p) {
    int res = 0;
    for (; p; p -= p & -p) res += ft[p];
    return res;
}
void solve() {
    string s;
    cin >> s;
    const int n = s.size();

    vi z(n);
    upd(z[0] = n);
    int k = 1;
    for (int i = 0; ++i < n;) {
        if (i < k + z[k]) z[i] = min(z[i - k], k + z[k] - i);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > k + z[k]) k = i;
        if (z[i]) upd(z[i]);
    }

    vii res;
    for (int i = 0; i++ < n;)
        if (z[n - i] == i) res.push_back({i, get(n) - get(i - 1)});

    write(res.size());
    for (auto& i : res) write(i.fi, i.se);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
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