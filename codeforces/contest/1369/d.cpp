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

const int M = 1e9 + 7;
const int N = 2e6 + 1;
vll res(N);

void init() {
    vvll u(N, vll(3, 0));
    u[1][0] = 1;

    for (int i = 2; i < N; ++i) {
        u[i][0] = (u[i - 1][0] + u[i - 1][1] * 2) % M;
        u[i][1] = u[i - 1][0];
        u[i][2] = (u[i - 1][1] + u[i - 1][2]) % M;
    }

    for (int i = 1; i < N; ++i) {
        res[i] = u[i - 1][1];
        if (i > 2) res[i] = (res[i] + res[i - 3]) % M;
    }

    for (auto& i : res) i = i * 4 % M;
}
void solve() {
    int n;
    cin >> n;
    print(res[n]);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    init();

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}

void print() { cout << "\n"; }
template <typename T, typename... Args>
void print(T x, Args... args) {
    cout << x << ' ';
    print(args...);
}
