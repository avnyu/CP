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

const ll N = 6e3 + 7;
const ll M = 1e7 + 7;
vvll dis(M);
map<ll, ll> p;

void init() {
    for (int i = 1; i < N; ++i)
        for (int j = 1; j < N; ++j)
            if (i * i + j * j < M) {
                int t = i * i + j * j;
                int x = sqrt(.5 + t);
                if (x * x == t) dis[t].push_back(i * N + j);
            }
}
void add(int x, int y, int w) { p[x * N + y] = w; }
void rem(int x, int y) { p.erase(x * N + y); }
void inc(int x, int y, int w) {
    if (p.find(x * N + y) != p.end()) p[x * N + y] += w;
}
void inc(int x, int y, int k, int w) {
    if (k == 0) {
        inc(x, y, w);
        return;
    }
    ll l = sqrt(0.5 + k);
    if (l * l == k)
        for (int i = -1; i < 2; i += 2) {
            inc(x + i * l, y, w);
            inc(x, y + i * l, w);
        }
    for (auto& ps : dis[k])
        for (int i = -1; i < 2; i += 2)
            for (int j = -1; j < 2; j += 2) {
                int x2 = x + (ps / N) * i, y2 = y + (ps % N) * j;
                inc(x2, y2, w);
            }
}
ll get(int x, int y) { return p.find(x * N + y) != p.end() ? p[x * N + y] : 0; }
ll get(int x, int y, int k) {
    if (k == 0) {
        return get(x, y);
    }
    ll res = 0;
    int l = sqrt(0.5 + k);
    if (l * l == k)
        for (int i = -1; i < 2; i += 2) {
            res += get(x + i * l, y);
            res += get(x, y + i * l);
        }
    for (auto& ps : dis[k])
        for (int i = -1; i < 2; i += 2)
            for (int j = -1; j < 2; j += 2) {
                int x2 = x + (ps / N) * i, y2 = y + (ps % N) * j;
                res += get(x2, y2);
            }
    return res;
}
void clear() { p.clear(); }
void solve(int T) {
    cout << "Case #" << T << ":\n";
    ll n, m, lastans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        add(x, y, w);
    }
    for (int i = 0; i < m; ++i) {
        ll t, x, y, w, k;
        cin >> t >> x >> y;
        x = (x + lastans) % 6000 + 1;
        y = (y + lastans) % 6000 + 1;
        if (t == 1) {
            cin >> w;
            add(x, y, w);
        } else if (t == 2) {
            rem(x, y);
        } else if (t == 3) {
            cin >> k >> w;
            inc(x, y, k, w);
        } else {
            cin >> k;
            lastans = get(x, y, k);
            print(lastans);
        }
    }
    clear();
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    init();

    int t = 1;
    cin >> t;
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
        cout << x << '\n';
    }
}