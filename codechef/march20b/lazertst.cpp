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
using namespace __gnu_pbds;

template <typename T>
using rbtree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void write();
template <typename T, typename... Args>
void write(T x, Args... args);
template <typename T>
void print_all(vector<T> &a);

void solve() {
    int n, m, k, q, t;
    cin >> n >> m >> k >> q;
    vector<ii> query(q);
    for (auto &i : query) cin >> i.fi >> i.se;

    if (k == 3) {
        cout << "2";
        for (; q--;) cout << " " << m - 1;
        cout << endl;
        cin >> t;
        if (t == -1) exit(0);
        return;
    }

    for (auto &i : query) {
        cout << "1 " << i.fi << ' ' << i.se << ' ' << (m + 1 >> 1) << endl;
        cin >> t;
        if (t == -1) exit(0);
        i.fi = t;
    }
    cout << "2";
    for (auto &i : query) cout << " " << i.fi;
    cout << endl;
    cin >> t;
    if (t == -1) exit(0);
}

int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
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
void print_all(vector<T> &a) {
    for (int i = 0; i < a.size(); ++i) cout << a[i] << " \n"[i == a.size() - 1];
}