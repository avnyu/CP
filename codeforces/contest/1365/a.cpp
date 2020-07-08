#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
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
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m));
    vi r(n);
    vi c(m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                r[i] = 1;
                c[j] = 1;
            }
        }
    int cntr = 0, cntc = 0;
    for (int i = 0; i < n; ++i) cntr += r[i] == 0;
    for (int j = 0; j < m; ++j) cntc += c[j] == 0;

    int x = min(cntc, cntr);
    write((x & 1) == 0 ? "Vivek" : "Ashish");
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
    for (int i = 0; i < a.size(); ++i) cout << a[i] << " \n"[i == a.size() - 1];
}