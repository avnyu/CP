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

const int N = 1e3 + 7;
vector<vector<ii>> a(N, vector<ii>(N));
vector<ii> moves = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
string s = "0DURLX";
vi rs = {0, 2, 1, 4, 3, 5};
vvi board(N, vi(N, -1));
ii X = {-1, -1};
int n;

void dfs(int u, int v, int x) {
    board[u][v] = x;
    for (int k = 1; k < 5; ++k) {
        int i = u + moves[k].fi;
        int j = v + moves[k].se;
        if (!board[i][j] && a[i][j] == a[u][v]) dfs(i, j, rs[k]);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) cin >> a[i][j].fi >> a[i][j].se;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) board[i][j] = 0;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (a[i][j] == X)
                for (int k = 1; k < 5; ++k) {
                    int u = i + moves[k].fi;
                    int v = j + moves[k].se;
                    if (a[u][v] == X) {
                        board[i][j] = k;
                        if (!board[u][v]) board[u][v] = rs[k];
                    }
                }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (a[i][j].fi == i && a[i][j].se == j) dfs(i, j, 5);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (board[i][j] == 0) {
                cout << "INVALID\n";
                return;
            }

    cout << "VALID\n";
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            cout << s[board[i][j]];
            if (j == n) cout << '\n';
        }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}

void write() { cout << "\n"; }
template <typename T, typename... Args>
void write(T x, Args... args) {
    cout << x << ' ';
    write(args...);
}
template <typename T>
void print_all(vector<T>& a) {
    for (auto i = a.begin(); i != a.end();) cout << *i << " \n"[++i == a.end()];
}