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

void solve() {
    int n, k;
    cin >> n >> k;
    k++;
    vi a(n);
    for (auto& i : a) cin >> i;
    int cnt = 0;
    vi b(n);
    for (int i = 0; i < n; ++i) cnt += a[i] == k / 2;
    cnt >>= 1;
    for (int i = 0; i < n; ++i)
        if (a[i] < k / 2)
            b[i] = 1;
        else if (a[i] > k / 2)
            b[i] = 0;
        else if (k % 2 == 0 || cnt) {
            b[i] = 0;
            cnt--;
        } else
            b[i] = 1;
    for (int i = 0; i < n; ++i) cout << b[i] << " \n"[i == n - 1];
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