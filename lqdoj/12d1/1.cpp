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

void solve() {
    int N = 2e6;
    vi p(N, 0);
    p[0] = p[1] = 1;
    for (int i = 2; i < N; ++i)
        if (!p[i]) {
            int j = i + i;
            while (j < N) {
                p[j] = 1;
                j += i;
            }
        }
    for (int i = 2; i < N; ++i)
        if (p[i] && p[i - 1]) p[i] += p[i - 1];
    for (int i = N - 1; i--;)
        if (p[i] && p[i + 1]) p[i] = p[i + 1];

    while (1) {
        int a;
        cin >> a;
        if (a == 0) break;
        print(p[a] ? p[a] + 1: 0);
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