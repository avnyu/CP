#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvii vector<vector<ii>>
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
    int n;
    cin >> n;
    vi a(n), b(n);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;

    multiset<ii> x, y;
    for (int i = 0; i < n / 2; ++i) {
        if (a[i] > a[n - 1 - i]) swap(a[i], a[n - 1 - i]);
        if (b[i] > b[n - 1 - i]) swap(b[i], b[n - 1 - i]);
        x.insert({a[i], a[n - 1 - i]});
        y.insert({b[i], b[n - 1 - i]});
    }

    if (n & 1 && a[n / 2] != b[n / 2]) {
        write("No");
        return;
    }

    vector<ii> A(all(x)), B(all(y));
    for (int i = 0; i < A.size(); ++i) {
        if (A[i].fi != B[i].fi || A[i].se != B[i].se) {
            write("No");
            return;
        }
    }
    write("Yes");
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