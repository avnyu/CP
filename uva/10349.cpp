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

const int M = 1e9 + 7;
int h, w;
vvi dp(41, vi(1 << 10));
vector<vector<bool>> grid(40, vector<bool>(10));

void gen(int row, int msk, int p = 0, int add = 0, int nxt = 0, int cnt = 0) {
    if (p == w) {
        // write("row+1", row + 1, "nxt", nxt, "row", row, "msk", msk, "add",
        // add,
        //       "cnt", cnt, dp[row + 1][nxt], dp[row][msk] + cnt);
        dp[row + 1][nxt] = min(dp[row + 1][nxt], dp[row][msk] + cnt);
        return;
    }
    if (!grid[row][p]) {
        gen(row, msk, p + 1, add, nxt, cnt);
        return;
    }
    if (msk & 1 << p) {
        gen(row, msk, p + 1, add, nxt, cnt);
        return;
    }
    if (add & 1 << p) {
        gen(row, msk, p + 1, add, nxt, cnt);
        return;
    }

    gen(row, msk, p + 1, add | 1 << p, nxt | 1 << p, cnt + 1);
    if (p < w - 1)
        gen(row, msk, p + 2, add | 1 << p | 1 << p + 1, nxt, cnt + 1);
}
void solve() {
    cin >> h >> w;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j) {
            char c;
            cin >> c;
            grid[i][j] = c == '*';
        }

    for (auto& i : dp) fill(all(i), M);
    dp[0][0] = 0;
    for (int i = 0; i < h; ++i) {
        for (int msk = 0; msk < 1 << w; ++msk) {
            if (dp[i][msk] == M) continue;

            // write("gen", i, msk);
            gen(i, msk);
        }
    }
    write(dp[h][0]);
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