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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

int fpow(int b, int n) {
    int r = 1;
    while (n) {
        if (n & 1) r *= b;
        n >>= 1;
        b *= b;
    }
    return r;
}
void solve() {
    int n, k, d;
    cin >> n >> k >> d;
    if (log(k) * d > log(1000000) || (log(k) * d < log(1000000000) && n <= fpow(k, d))) {
        vvi a(n, vi(d, 1));
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < d; ++j) a[i][j] = a[i - 1][j];
            for (int j = d; j--;) {
                if (j == d - 1) a[i][j]++;
                if (a[i][j] > k) {
                    a[i][j] = 1;
                    a[i][j - 1]++;
                }
            }
        }
        for (int j = 0; j < d; ++j)
            for (int i = 0; i < n; ++i) cout << a[i][j] << " \n"[i == n - 1];
    } else
        print(-1);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
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
        cout << x << '\n';
    }
}