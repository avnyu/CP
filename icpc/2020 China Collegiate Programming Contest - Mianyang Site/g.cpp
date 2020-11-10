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

const int N = 20;
int dp[N][N][N][N];
vvi step = {{-1, 0, 0, 0}, {0, -2, 1, 0}, {0, -1, -1, 1}};

int dfs(int i, int j, int k, int l) {
    if (dp[i][j][k][l]) return dp[i][j][k][l];
    if (i + j + k + l < 2) return dp[i][j][k][l] = 2;
    dp[i][j][k][l] = 2;
    for (auto& s : step)
        if (i + s[0] >= 0 && j + s[1] >= 0 && k + s[2] >= 0 && l + s[3] >= 0 &&
            dfs(i + s[0], j + s[1], k + s[2], l + s[3]) == 2)
            dp[i][j][k][l] = 1;

    return dp[i][j][k][l];
}
void init() {
    for (int l = 0; l < N; ++l)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                for (int k = 0; k < N; ++k) {
                    dp[i][j][k][l] = dfs(i, j, k, l);
                }
}
void solve(int T) {
    int c0, c1, c2, c3;
    cin >> c0 >> c1 >> c2 >> c3;
    vector<string> name = {"Rabbit", "Horse"};
    cout << "Case #" << T << ": ";

    if (c1 == 0 && c2 == 0) {
        if (c0 + c3 < 2)
            print(name[1]);
        else if (c0 == 0)
            print(name[1]);
        else if (c3 == 0)
            print(name[c0 & 1]);
        else
            print(name[c0 % 2 == 0]);
    } else if (c0 < N && c1 < N && c2 < N) {
        print(name[dp[c0][c1][c2][0] - 1]);
    } else if (c0 & 1) {
        bool h = true;
        if (c1 % 3 == 0) h = false;
        if (c1 % 3 == 1 && c2 == 0) h = false;
        if (c1 % 3 == 2 && c2 > 1) h = false;
        print(name[h]);
    } else {
        bool h = true;
        if (c1 % 3 == 1 && c2) h = false;
        if (c1 % 3 == 2) h = false;
        print(name[h]);
    }

    // for (int i = 0; i < N; ++i) {
    //     print(i);
    //     for (int j = 0; j < 7; ++j)
    //         for (int k = 0; k < 7; ++k) cout << dp[i][j][k][1] << " \n"[k == 6];
    //     cout << '\n';
    // }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    init();

    int t = 1;
    cin >> t;
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