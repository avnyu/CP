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
void print_all(vector<T> &a);

const int N = 1e6 + 1;
vector<int> cnt(N);
void add(int p, int v) {
    for (; p < N; p += p & -p) cnt[p] += v;
}
int get(int p) {
    int s = 0;
    for (; p; p -= p & -p) s += cnt[p];
    return s;
}
void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        add(v, 1);
    }
    for (int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        if (k > 0)
            add(k, 1);
        else {
            k = -k;
            int l = 0, r = 1e6, x = 0;
            while (l <= r) {
                int m = l + r >> 1;
                if (get(m) >= k) {
                    x = m;
                    r = m - 1;
                } else
                    l = m + 1;
            }
            add(x, -1);
        }
    }
    if (get(int(1e6)) == 0)
        write("0");
    else {
        for (int i = 1; i < N; ++i)
            if (cnt[i]) {
                write(i);
                break;
            }
    }
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
void print_all(vector<T> &a) {
    for (int i = 0; i < a.size(); ++i) cout << a[i] << " \n"[i == a.size() - 1];
}