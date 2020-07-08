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

const int N = 1e6 + 1;
const int sN = 1e3 + 1;

int n;
vi a(N), prime(N, 1), dis(N), bfs(N);
vvii g(N);
bitset<N> in;

void init() {
    iota(all(prime), 0);
    for (int i = 2; i < N; ++i)
        if (prime[i] == i && 1LL * i * i < N)
            for (int j = i * i; j < N; j += i) prime[j] = i;
}

int add(int u, int v, int i) {
    if (u > v) swap(u, v);
    g[u].push_back({v, i});
    g[v].push_back({u, i});
    return N;
}

void solve() {
    init();
    cin >> n;
    int loop = N;
    for (int i = 0; i < n; ++i) {
        unordered_map<int, int> um;
        int x;
        cin >> x;
        if (x == 1) {
            loop = 1;
            continue;
        }

        while (x != 1) {
            um[prime[x]] ^= 1;
            x /= prime[x];
        }

        int u = 1, v = 1;
        auto t = um.begin();
        if (t->se) u = t->fi;
        ++t;
        if (t != um.end() && t->se) v = t->fi;
        add(u, v, i);
    }

    if (loop != N) {
        write(loop);
        return;
    }

    int mn = N;
    for (int i = 1; i < sN; ++i)
        if (prime[i] == i) {
            int s = 0, tmp = N;
            bfs[s++] = i;
            fill(all(dis), 0);
            dis[i] = 1;
            in.reset();

            for (int j = 0; j < s; ++j)
                for (auto &e : g[bfs[j]]) {
                    int &v = e.fi, &t = e.se, &u = bfs[j];
                    if (in.test(t)) continue;
                    in.set(t);
                    if (dis[v])
                        tmp = min(tmp, dis[u] + dis[v] - 1);
                    else {
                        dis[v] = dis[u] + 1;
                        bfs[s++] = v;
                    }
                }

            mn = min(mn, tmp);
        }

    write(mn != N ? mn : -1);
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