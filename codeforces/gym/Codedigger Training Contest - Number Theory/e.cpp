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

const int N = 1e7 + 7;
const int M = 2e9;
vi minP(N), maxP(N);

void init() {
    iota(all(minP), 0);
    iota(all(maxP), 0);
    for (int i = 2; i < N; ++i)
        if (minP[i] == i)
            for (int j = i + i; j < N; j += i) {
                minP[j] = min(minP[j], i);
                maxP[j] = i;
            }
}
void solve() {
    int x, a, b, c;
    cin >> x >> a >> b >> c;

    a = maxP[x] != x ? a + x / maxP[x] : M;
    b = minP[x / minP[x]] != x / minP[x] ? b + minP[x] : M;
    c = c + x;

    print(min(a, min(b, c)));
    // print(a, b, c);
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
    if (sizeof...(args)) {
        cout << x << ' ';
        print(args...);
    } else {
        cout << x << '\n';
    }
}