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

void solve(int test_case) {
    int n, x;
    cin >> n >> x;
    vi a(n), b(n);
    for (int i = n; i--;) cin >> a[i];
    for (int i = n; i--;) cin >> b[i];

    vector<vector<bool>> state(n + 1, vector<bool>(n + 1, true));
    int ans = 0;

    state[n][n] = false;

    for (int i = n + 1; i--;)
        for (int j = n + 1; j--;)
            if (state[i][j]) {
                ans++;
                int sum = 0;
                for (int k = i; k--;) {
                    sum += a[k];
                    if (sum > x) break;
                    state[k][j] = false;
                }
                sum = 0;
                for (int k = j; k--;) {
                    sum += b[k];
                    if (sum > x) break;
                    state[i][k] = false;
                }
            }

    cout << "Case #" << test_case << '\n';
    print((n + 1) * (n + 1) - ans, ans);
    for (int i = n + 1; i--;)
        for (int j = n + 1; j--;) print(i, j, state[i][j]);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

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