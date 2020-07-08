#include <bits/stdc++.h>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
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
    int n;
    cin >> n;
    vi a(n);
    vvi pos(201), cnt(201, vi(n));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]].push_back(i);
        cnt[a[i]][i]++;
    }
    for (auto& i : cnt) partial_sum(all(i), i.begin());

    int rs = 0;
    for (auto& i : pos) rs = max(rs, int(i.size()));

    for (int i = 0; i < 201; ++i) {
        int l = 0, r = pos[i].size() - 1;
        while (l < r) {
            int &pl = pos[i][l], &pr = pos[i][r], mx = 0;

            for (int j = 0; j < 201; ++j)
                mx = max(mx, cnt[j][pr - 1] - cnt[j][pl]);

            rs = max(rs, l + l + 2 + mx);

            l++;
            r--;
        }
    }

    write(rs);
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
