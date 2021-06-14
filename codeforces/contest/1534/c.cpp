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
    int n;
    cin >> n;
    vvi a(2, vi(n));
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            a[i][j]--;
        }

    vvi p(2, vi(n));
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < n; ++j) p[i][a[i][j]] = j;

    int M = 1e9 + 7;
    int cur = 1;

    for (int i = 0; i < n; ++i) {
        if (a[0][i] == -1) continue;

        cur = (cur << 1) % M;

        while (a[0][i] != -1) {
            a[0][i] = -1;
            i = p[0][a[1][i]];
        }
    }

    print(cur);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

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