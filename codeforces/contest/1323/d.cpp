#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
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
template <typename T>
void print_all(vector<T>& a);

void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    const int N = 25;
    int rs = 0, cnt[2];
    for (int bit = 0; bit < N; ++bit) {
        cnt[0] = cnt[1] = 0;
        for (auto& i : a) cnt[i & 1 << bit ? 1 : 0]++;
        rs ^= cnt[0] & cnt[1] & 1 ? 1 << bit : 0;

        for (int i = 0; i < n; ++i) b[i] = a[i] & (1 << bit) - 1;
        sort(all(b));
        for (int i = 0; i < n; ++i) {
            int l = (1 << bit) - b[i];
            int r = (1 << bit + 1) - b[i];
            rs ^= lower_bound(b.begin(), b.begin() + i, r) -
                              lower_bound(b.begin(), b.begin() + i, l) &
                          1
                      ? 1 << bit
                      : 0;
        }
    }
    write(rs);
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
template <typename T>
void print_all(vector<T>& a) {
    for (int i = 0; i < a.size(); ++i) cout << a[i] << " \n"[i == a.size() - 1];
}