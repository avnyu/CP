#include <bits/stdc++.h>

#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define ii pair<int, int>
#define vii vector<ii>
#define vvii vector<vii>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define prt(u, v) \
    for (auto x = u; x != v;) cout << (*x) << " \n"[++x == v];

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) cin >> a[i][j];
    vi c(2);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'R') {
                int &t = c[(i + j) % 2];
                if (t == 0)
                    t = 1;
                else if (t == 2) {
                    print("NO");
                    return;
                }
            }
            if (a[i][j] == 'W') {
                int &t = c[(i + j) % 2];
                if (t == 0)
                    t = 2;
                else if (t == 1) {
                    print("NO");
                    return;
                }
            }
        }
    if (c[0] == 0 && c[1] == 0) {
        c[0] = 1;
        c[1] = 2;
    } else if (c[0] == 0) {
        c[0] = c[1] == 1 ? 2 : 1;
    } else if (c[1] == 0) {
        c[1] = c[0] == 1 ? 2 : 1;
    } else if (c[0] == c[1]) {
        print("NO");
        return;
    }

    print("YES");
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cout << (c[(i + j) % 2] == 1 ? "R" : "W")
                 << (j == m - 1 ? "\n" : "");
}
int main() {
    ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    cin >> t;
    for (int i = 0; i++ < t;) solve();

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