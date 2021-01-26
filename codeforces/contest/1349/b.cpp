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

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) a[i] = (a[i] < k ? 0 : a[i] == k ? 1 : 2);

    int ok = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] == 1) {
            ok = 1;
            break;
        }
    if (n == 1 && ok) {
        cout << "YES\n";
        return;
    }

    for (int i = 0; i < n; ++i)
        if (i + 1 < n && a[i] && a[i + 1]) {
            ok++;
            break;
        } else if (i + 2 < n && a[i] && a[i + 2]) {
            ok++;
            break;
        }

    cout << (ok > 1 ? "YES\n" : "NO\n");
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
        cout << x << '\n';
    }
}