#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define iiii tuple<int, int, int, int>
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

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    const int N = 2e4 + 7;
    int resa, resb, res = 1e9;
    vi costb(N, 1e9), resc(N, 1e9);
    for (int i = 1; i < N; ++i)
        for (int j = i; j < N; j += i) {
            int x = abs(b - i) + abs(c - j);
            if (x < costb[i]) {
                costb[i] = x;
                resc[i] = j;
            }
        }

    for (int i = 1; i < N; ++i)
        for (int j = i; j < N; j += i) {
            int x = costb[j] + abs(a - i);
            if (x < res) {
                res = x;
                resa = i;
                resb = j;
            }
        }
    cout << res << '\n';
    write(resa, resb, resc[resb]);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
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