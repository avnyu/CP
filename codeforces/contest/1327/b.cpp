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
#define what_is(x) cerr << #x << " is " << x << endl;

using namespace std;

void write();
template <typename T, typename... Args>
void write(T x, Args... args);

void solve() {
    int n;
    cin >> n;
    vi available(n + 1, 1), lis(n + 1);

    int cnt = 0, princess;
    for (int i = 0; i < n; ++i) {
        int k, get = 0;
        cin >> k;

        for (int j = 0; j < k; ++j) cin >> lis[j];

        for (int j = 0; j < k; ++j)
            if (available[lis[j]]) {
                cnt++;
                available[lis[j]] = 0;
                get = 1;
                break;
            }

        if (!get) princess = i + 1;
    }
    int prince = 0;
    for (int i = 1; i <= n; ++i)
        if (available[i]) prince = i;

    write((cnt == n ? "OPTIMAL" : "IMPROVE"));
    if (cnt != n) write(princess, prince);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}
template <typename T, typename... Args>
void write(T x, Args... args) {
    cout << x;
    if (sizeof...(args)) {
        cout << ' ';
        write(args...);
    } else
        cout << '\n';
}