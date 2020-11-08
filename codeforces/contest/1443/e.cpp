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

const int N = 9;
const int M = 2e5 + 7;
vvi per;
vi a(M), tail(N + N);
vll pfs(M + 1);
int n, q, cur, per_s;

void init() {
    iota(a.begin(), a.end(), 0);
    for (int i = 0; i < M; ++i) pfs[i + 1] = pfs[i] + a[i];
    // print("init pfs");

    vi p(N);
    iota(p.begin(), p.end(), 0);
    do {
        per.push_back(p);
    } while (next_permutation(p.begin(), p.end()));
    per_s = per.size();
    cur = 0;
    // print("init permutation");

    int x = n, y = N + N;
    while (x-- && y--) {
        tail[y] = x;
    }
    // print("init tail");

    // print("permu size", per_s);
    // cout.flush();
}
void reassign() {
    sort(tail.rbegin(), tail.rbegin() + N);
    next_permutation(tail.begin(), tail.end());
}
ll get(int l, int r) {
    --l, --r;
    int x = n, y = N + N;
    ll res = 0;

    // print("get", l, r, x, y, cur);
    // print("per");
    // for (int i = 0; i < N; ++i) cout << per[cur][i] << " \n"[i == N - 1];
    // print("tail");
    // for (int i = 0; i < N + N; ++i) cout << tail[i] << " \n"[i == N + N - 1];

    // cout << l << ' ' << r << ' ' << x << ' ' << y << endl;
    while (x-- && y--) {
        if (x <= r && x >= l) {
            // cout << l << ' ' << r << ' ' << x << ' ' << y << endl;
            if (y >= N)
                res += tail[per[cur][y - N] + N];
            else
                res += tail[y];
            r--;
        }
    }

    if (l <= r) res += pfs[r + 1] - pfs[l];

    return res;
}
void jump(int x) {
    if (cur + x >= per_s) reassign();
    cur = (cur + x) % per_s;
}
void solve() {
    int n, q;
    cin >> n >> q;

    init();

    while (q--) {
        int t, x, l, r;
        cin >> t;

        if (t == 1) {
            cin >> l >> r;
            // print("query 1", l, r);
            print(get(l, r) + r - l + 1);
        } else {
            cin >> x;
            // print("query 2", x);
            jump(x);
        }
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

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