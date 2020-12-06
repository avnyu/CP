#include <bits/stdc++.h>

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
#define lcm(a, b) (long long)a / __gcd(a, b) * b
#define debug(x) cerr << #x << ' ' << x << '\n'
#define prt(u) \
    for (auto &i : u) cout << i << " \n"[&i == &u.back()];

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) cin >> a[i][j];

    auto tcol = [&](int u, int v) {
        if (u < 0 || u >= n - 2 || v < 0 || v >= n) return false;
        int cnt = 0;
        for (int i = u; i < u + 3; ++i) cnt += a[i][v] == 'O';
        return cnt == 3 || cnt == 0;
    };
    auto trow = [&](int u, int v) {
        if (u < 0 || u >= n - 2 || v < 0 || v >= n) return false;
        int cnt = 0;
        for (int i = u; i < u + 3; ++i) cnt += a[v][i] == 'O';
        return cnt == 3 || cnt == 0;
    };
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) cout << a[i][j] << (j == n - 1 ? "\n" : "");
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

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
        cout << x << endl;
    }
}
