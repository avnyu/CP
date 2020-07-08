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
    int n;
    cin >> n;
    vi odd, even;
    for (int i = 0; i < n + n; ++i) {
        int x;
        cin >> x;
        if (x & 1)
            odd.push_back(i + 1);
        else
            even.push_back(i + 1);
    }

    if (odd.size() & 1) {
        odd.pop_back();
        even.pop_back();
    } else if (odd.empty()) {
        even.pop_back();
        even.pop_back();
    } else {
        odd.pop_back();
        odd.pop_back();
    }

    while (odd.size()) {
        int u = odd.back();
        odd.pop_back();
        int v = odd.back();
        odd.pop_back();
        write(u, v);
    }
    while (even.size()) {
        int u = even.back();
        even.pop_back();
        int v = even.back();
        even.pop_back();
        write(u, v);
    }
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
