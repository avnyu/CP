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

vi blk = {0, 1, 2, 9, 10, 11, 18, 19, 20};

void change(vector<char>& a, int b, int p) {
    int x = p / 9;
    int y = p % 9;
    vi cnt(10, 0);
    cnt[a[p] - '0'] = -1;
    for (int i = 0; i < 9; ++i)
        cnt[a[x * 9 + i] - '0']++, cnt[a[i * 9 + y] - '0']++,
            cnt[a[b + blk[i]] - '0']++;
    for (int i = 0; i++ < 9;)
        if (cnt[i] == 3) a[p] = '0' + i;
}
void solve() {
    vector<char> a(81);
    for (int i = 0; i < 81; ++i) {
        cin >> a[i];
    }
    vi p = {0, 12, 24, 28, 40, 52, 56, 68, 80};
    vi b = {0, 3, 6, 27, 30, 33, 54, 57, 60};
    for (int i = 0; i < 9; ++i) change(a, b[i], p[i]);
    for (int i = 0; i < 81; ++i) cout << a[i] << (i % 9 == 8 ? "\n" : "");
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
