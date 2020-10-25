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

bool check_prime(int x) {
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0) return false;
    return true;
}
void solve() {
    int n;
    cin >> n;
    vvi a(n, vi(n, 1));
    int x;
    for (int i = 0; i <= int(1e5); ++i)
        if (check_prime(i + n - 1) && !check_prime(i)) x = i;
    for (int i = 1; i < n; ++i) a[i][0] = a[0][i] = x;

    a[0][0] = a[0][1] * (n - 1);
    for (int i = 0; i <= int(1e5); ++i)
        if (check_prime(a[0][0] + i) && !check_prime(i)) {
            a[0][0] = i;
            break;
        }
    if (a[0][0] == a[0][1] * (n - 1)) {
        while (1) {
            int t = 1;
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) cout << a[i][j] << " \n"[j == n - 1];
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

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