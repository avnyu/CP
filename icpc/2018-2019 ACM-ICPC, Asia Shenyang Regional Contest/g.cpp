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

const int N = 6e3 + 7;
const int M = 1e7 + 7;
ll lastans;
vvi dis(M);
vi p2(N);
vvi p(N, vi(N, 0));
queue<int> sav;

int _sqrt(int k) {
    int res = 0, x = 1 << 15;
    while (x) {
        res += x;
        if (res * res > k) res -= x;
        x >>= 1;
    }
    return res;
}
void init() {
    lastans = 0;
    for (int i = 0; i < N; ++i) p2[i] = i * i;
    for (int i = 1; i < N; ++i)
        for (int j = 1; j < N; ++j)
            if (p2[i] + p2[j] < M) {
                int t = p2[i] + p2[j];
                dis[t].push_back(i * N + j);
            }
}
void add(int x, int y, int w) {
    if (x < 1 || x >= N || y < 1 || y >= N) return;
    sav.push(x * N + y);
    p[x][y] = w;
}
void rem(int x, int y) {
    if (x < 1 || x >= N || y < 1 || y >= N) return;
    p[x][y] = 0;
}
void inc(int x, int y, int w) {
    if (x < 1 || x >= N || y < 1 || y >= N) return;
    if (p[x][y]) p[x][y] += w;
}
void inc(int x, int y, int k, int w) {
    if (k == 0) {
        inc(x, y, w);
        return;
    }
    int sk = _sqrt(k), x2, y2;
    if (p2[sk] == k)
        for (int i = -1; i < 2; i += 2) {
            inc(x + i * sk, y, w);
            inc(x, y + i * sk, w);
        }
    for (int i = -1; i < 2; i += 2)
        for (int j = -1; j < 2; j += 2)
            for (auto& ps : dis[k]) {
                x2 = x + ps / N * i;
                y2 = y + ps % N * j;
                inc(x2, y2, w);
            }
}
ll get(int x, int y) {
    if (x < 1 || x >= N || y < 1 || y >= N) return 0;
    return p[x][y];
}
ll get(int x, int y, int k) {
    if (k == 0) {
        return get(x, y);
    }
    ll res = 0;
    int sk = _sqrt(k), x2, y2;
    if (p2[sk] == k)
        for (int i = -1; i < 2; i += 2) {
            res += get(x + i * sk, y);
            res += get(x, y + i * sk);
        }
    for (int i = -1; i < 2; i += 2)
        for (int j = -1; j < 2; j += 2)
            for (auto& ps : dis[k]) {
                x2 = x + ps / N * i;
                y2 = y + ps % N * j;
                res += get(x2, y2);
            }
    return res;
}
void clear() {
    while (sav.size()) {
        int x = sav.front() / N;
        int y = sav.front() % N;
        p[x][y] = 0;
        sav.pop();
    }
}
void solve(int T) {
    lastans = 0;

    cout << "Case #" << T << ":\n";
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        add(x, y, w);
    }
    for (int i = 0; i < m; ++i) {
        int t, x, y, w, k;
        cin >> t >> x >> y;
        x = (lastans + x) % 6000 + 1;
        y = (lastans + y) % 6000 + 1;
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