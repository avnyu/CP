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

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int N = 5e2 + 7;
map<string, int> to_int;
vvi is_a(N);
vvi has_a(N);
vi is_pass(N);
vi has_pass(N);

bool test_is_a(int x, int y) {
    if (is_pass[x]) return false;
    is_pass[x] = 1;
    if (x == y) return true;

    for (auto& z : is_a[x])
        if (test_is_a(z, y)) return true;

    return false;
}
bool test_has_a(int x, int y, int p = 0) {
    for (auto& z : has_a[x]) {
        if (!has_pass[z]) {
            has_pass[z] = 1;
            if (z == y) return true;
            if (test_has_a(z, y, 1)) return true;
        }
    }
    for (auto& z : is_a[x]) {
        if (!is_pass[z]) {
            if (p) is_pass[z] = 1;
            if (p && z == y) return true;
            if (test_has_a(z, y, p)) return true;
        }
    }
    return false;
}
void solve() {
    int n, m;
    cin >> n >> m;
    int pos = 0;
    for (int i = 0; i < n; ++i) {
        string s, r, t;
        cin >> s >> r >> t;

        if (to_int.find(s) == to_int.end()) to_int[s] = pos++;
        if (to_int.find(t) == to_int.end()) to_int[t] = pos++;

        if (r[0] == 'i')
            is_a[to_int[s]].push_back(to_int[t]);
        else
            has_a[to_int[s]].push_back(to_int[t]);
    }
    for (int i = 0; i < m; ++i) {
        string s, r, t;
        cin >> s >> r >> t;

        bool ok;
        if (r[0] == 'i')
            ok = test_is_a(to_int[s], to_int[t]);
        else
            ok = test_has_a(to_int[s], to_int[t]);

        cout << "Query " << i + 1 << ": ";
        print(ok ? "true" : "false");

        fill(all(is_pass), 0);
        fill(all(has_pass), 0);
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

void print() { cout << "\n"; }
template <typename T, typename... Args>
void print(T x, Args... args) {
    if (sizeof...(args)) {
        cout << x << ' ';
        print(args...);
    } else {
        cout << x << '\n';
    }
}