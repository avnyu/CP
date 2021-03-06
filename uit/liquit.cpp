#include <bits/stdc++.h>
// #pragma gcc optimize("O3")
#define ll long long
#define ii pair<int, int>
#define pll pair<ll, ll>
#define dd pair<double, double>
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vii vector<ii>
#define vll vector<pll>
#define vdd vector<dd>
#define vvi vector<vi>
#define vvl vector<vl>
#define vvd vector<vd>
#define vvii vector<vii>
#define vvll vector<vll>
#define vvdd vector<vdd>
#define fi first
#define se second
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define iii tuple<int, int, int>
#define iiii tuple<int, int, int, int>

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int M = 1e9 + 7;
const ll N = 1e6 + 7;
int k, i, j, t;
ll x, y, z, key;
unordered_set<ll> in;
queue<pair<ll, int>> q;
vl n(3), a(3), b(3), u(3);

bool test() {
    x = u[0], y = u[1], z = u[2];
    if (x > y) swap(x, y);
    if (x > z) swap(x, z);
    if (y > z) swap(y, z);
    return x == b[0] && y == b[1] && z == b[2];
}
int bfs() {
    key = a[0] * N * N + a[1] * N + a[2];
    in.insert(key);
    q.push({key, 0});

    while (!q.empty()) {
        key = q.front().fi;
        k = q.front().se;

        u[0] = key / N / N;
        u[1] = key / N % N;
        u[2] = key % N;

        if (test()) return k;
        q.pop();

        for (i = 0; i < 3; ++i)
            for (j = 0; j < 3; ++j) {
                if (i == j) continue;
                if (u[i] == 0) continue;
                if (u[j] == n[j]) continue;

                t = min(u[i], n[j] - u[j]);

                u[i] -= t;
                u[j] += t;

                key = u[0] * N * N + u[1] * N + u[2];
                if (in.find(key) == in.end()) {
                    in.insert(key);
                    q.push({key, k + 1});
                }

                u[i] += t;
                u[j] -= t;
            }
    }

    while (q.size()) q.pop();

    return M;
}
void solve(int T) {
    for (i = 0; i < 3; ++i) cin >> n[i];
    for (i = 0; i < 3; ++i) cin >> a[i];
    for (i = 0; i < 3; ++i) cin >> b[i];
    sort(b.begin(), b.end());

    ll res = bfs();
    cout << (res == M ? -1 : res) << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int i = 0; i++ < t;) solve(i);

    return 0;
}
void print() { cout << "\n"; }
template <typename T, typename... Args>
void print(T x, Args... args) {
    if (sizeof...(args)) {
        cout << x << ' ';
        print(args...);
    } else {
        cout << x << endl;
    }
}