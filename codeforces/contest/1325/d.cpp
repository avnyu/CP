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

const int N = 1e5 + 7;
int n, num;
vi h(N), res(N), in(N);
vector<vector<ii>> g(N);

void solve() {
    ll x, s;
    cin >> x >> s;

    if (x > s || (s - x & 1) != 0) {
        cout << "-1\n";
        return;
    }

    if (x == 0 && s == 0) {
        cout << "0\n";
        return;
    }

    if (x == s) {
        cout << "1\n" << x << '\n';
        return;
    }

    ll z = s - x >> 1;
    if (((x + z) ^ z) == x) {
        cout << "2\n" << x + z << ' ' << z << '\n';
        return;
    }
    cout << "3\n" << x << ' ' << z << ' ' << z << '\n';
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