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
    int r0, c0;
    cin >> r0 >> c0;
    vector<ii> fullPath = {{2, 2}, {3, 1}, {8, 6}, {6, 8}, {1, 3},
                           {2, 2}, {3, 3}, {5, 1}, {8, 4}, {4, 8},
                           {1, 5}, {3, 3}, {4, 4}, {7, 1}, {8, 2},
                           {2, 8}, {1, 7}, {4, 4}, {8, 8}};
    vector<ii> toBegin;
    if (r0 != c0) toBegin.push_back({r0 + c0 >> 1, r0 + c0 >> 1});
    if ((r0 + c0 >> 1) != 1) toBegin.push_back({1, 1});
    cout << toBegin.size() + fullPath.size() << '\n';
    for (auto& i : toBegin) cout << i.fi << ' ' << i.se << '\n';
    for (auto& i : fullPath) cout << i.fi << ' ' << i.se << '\n';
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