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

const int N = 5e4;

void write();
template <typename T, typename... Args>
void write(T x, Args... args);
template <typename T>
void print_all(vector<T>& a);

int random() {
    return rand() % 30001 - 15000;
}
void solve() {
    int n = 5e4;
    write(n);
    for (int i = 0; i < n; ++i) cout << random() << " \n"[i == n - 1];
    write(n);
    for (int i = 0; i < n; ++i) {
        int l = rand() % 10000 + 1, r = rand() % 10000 + 30000;
        if (l > r) swap(l, r);
        write(l, r);
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    srand(time(nullptr));
    freopen("in", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}

void write() {
    cout << "\n";
}
template <typename T, typename... Args>
void write(T x, Args... args) {
    cout << x << ' ';
    write(args...);
}
template <typename T>
void print_all(vector<T>& a) {
    for (int i = 0; i < a.size(); ++i) cout << a[i] << " \n"[i == a.size() - 1];
}