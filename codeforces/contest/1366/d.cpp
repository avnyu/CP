#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
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
    int N = 1e7 + 1;
    vi pri(N);
    iota(all(pri), 0);
    for (int i = 2; i < N; ++i)
        if (pri[i] == i)
            for (int j = i + i; j < N; j += i)
                if (pri[j] == j) pri[j] = i;
    int n;
    cin >> n;
    vi d1(n), d2(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (pri[a] == a) {
            d1[i] = d2[i] = -1;
        } else {
            int x = pri[a];
            while (a % x == 0) a /= x;
            if (a == 1)
                d1[i] = d2[i] = -1;
            else
                d1[i] = x, d2[i] = a;
        }
    }
    for (int i = 0; i < n; ++i) cout << d1[i] << " \n"[i == n - 1];
    for (int i = 0; i < n; ++i) cout << d2[i] << " \n"[i == n - 1];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
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
