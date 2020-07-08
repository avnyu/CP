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

void write();
template <typename T, typename... Args>
void write(T x, Args... args);

const int M = 1e9 + 7;
int fpow(int b, int n, const int m = M) {
    int res = 1;
    while (n) {
        if (n & 1) res = 1LL * res * b % m;
        n >>= 1;
        b = 1LL * b * b % m;
    }
    return res;
}
void solve() {
    int n;
    cin >> n;
    int p = 0;
    vi basis(30), prime(71), pos(71);
    iota(all(prime), 0);
    for (int i = 2; i < 71; ++i)
        if (prime[i] == i) {
            pos[i] = p++;
            for (int j = i + i; j < 71; j += i) prime[j] = i;
        }

    int sz = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int key = 0;
        while (x > 1) {
            key ^= 1 << pos[prime[x]];
            x /= prime[x];
        }

        for (int j = 0; j < basis.size(); ++j)
            if (key & 1 << j)
                if (basis[j])
                    key ^= basis[j];
                else {
                    sz++;
                    basis[j] = key;
                    break;
                }
    }
    write((M - 1 + fpow(2, n - sz)) % M);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}
template <typename T, typename... Args>
void write(T x, Args... args) {
    cout << x;
    if (sizeof...(args)) {
        cout << ' ';
        write(args...);
    } else
        cout << '\n';
}