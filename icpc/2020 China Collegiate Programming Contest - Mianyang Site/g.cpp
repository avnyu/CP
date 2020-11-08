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

const int N = 207;
int dp[N][N][N];
vvi step = {{-1, 0, 0}, {0, -2, 1}, {0, -1, -1}};

int get(int c0, int c1, int c2, int c3) {
    if (c0 + c1 + c2 + c3 == 0) return 1;

    if (c1 == 0 && c2 == 0 && c3 == 0) return c0 % 2;

    int win = 0;

    if (c1 % 3 == 0 || (c1 % 3 == 1 && c2 == 0))
        win = 1;
    else
        win = 0;

    win = (win + c0) % 2;
    return win;
}
int dfs(int i, int j, int k) {
    if (i < 0 || j < 0 || k < 0 || i >= N || j >= N || k >= N) return 1;
    if (dp[i][j][k]) return dp[i][j][k];
    dp[i][j][k] = 2;
    for (auto& s : step)
        if (dfs(i + s[0], j + s[1], k + s[2]) == 2) dp[i][j][k] = 1;

    return dp[i][j][k];
}
void init() {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k) dp[i][j][k] = dfs(i, j, k);
}
void solve(int T) {
    init();

    // int c0, c1, c2, c3;
    // cin >> c0 >> c1 >> c2 >> c3;
    vector<string> name = {"Rabbit", "Horse"};
    cout << "Case #" << T << ": ";

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k) {
                print(i, j, k, dp[i][j][k] - 1, get(i, j, k, 0));
            }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int i = 0; i++ < t;) solve(i);

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