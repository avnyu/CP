#include <bits/stdc++.h>

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
#define prt(v) \
    for (auto& i : v) cout << i << " \n"[&i == &v.back()]

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int N = 1 << 4;
vi maxit(N << 1), minit(N << 1);
vi alz(N << 1), rlz(N << 1);
vi apr(N << 1), rpr(N << 1);

void add(int i, int v, int pr) {
    maxit[i] = max(maxit[i], v);
    minit[i] = max(minit[i], v);
    // alz[i] = v;

    if (i == N + 6) print("add", i, v, pr);

    if (pr < max(apr[i], rpr[i])) print("Wrong");

    if (v >= alz[i]) {
        apr[i] = pr;
        alz[i] = v;
    } else if (apr[i] < rpr[i] && rlz[i] <= v) {
        apr[i] = pr;
        alz[i] = v;
    } else if (apr[i] < rpr[i] && rlz[i] <= alz[i]) {
        apr[i] = pr;
        alz[i] = v;
    }
}
void rem(int i, int v, int pr) {
    maxit[i] = min(maxit[i], v);
    minit[i] = min(minit[i], v);
    // rlz[i] = v;

    if (i == N + 6) print("rem", i, v, pr);

    if (pr < max(apr[i], rpr[i])) print("Wrong");

    if (v <= rlz[i]) {
        rpr[i] = pr;
        rlz[i] = v;
    } else if (rpr[i] < apr[i] && alz[i] >= v) {
        rpr[i] = pr;
        rlz[i] = v;
    } else if (rpr[i] < apr[i] && alz[i] >= rlz[i]) {
        rpr[i] = pr;
        rlz[i] = v;
    }
}
void push(int i) {
    if (i >= N) return;
    if (apr[i] > rpr[i]) {
        if (alz[i]) {
            add(i << 1, alz[i], apr[i]);
            add(i << 1 | 1, alz[i], apr[i]);
            alz[i] = 0;
        }
        if (rlz[i]) {
            rem(i << 1, rlz[i], rpr[i]);
            rem(i << 1 | 1, rlz[i], rpr[i]);
            rlz[i] = 0;
        }
    } else {
        if (rlz[i]) {
            rem(i << 1, rlz[i], rpr[i]);
            rem(i << 1 | 1, rlz[i], rpr[i]);
            rlz[i] = 0;
        }
        if (alz[i]) {
            add(i << 1, alz[i], apr[i]);
            add(i << 1 | 1, alz[i], apr[i]);
            alz[i] = 0;
        }
    }
}
void upd(int i) {
    maxit[i] = max(maxit[i << 1], maxit[i << 1 | 1]);
    minit[i] = min(minit[i << 1], minit[i << 1 | 1]);
}
void mod(int b, int e, int v, int pr, int i = 1, int l = 0, int r = N - 1) {
    push(i);
    if (l > e || r < b) return;
    if (b <= l && r <= e) {
        if (v > 0)
            add(i, v, pr);
        else
            rem(i, -v, pr);
        return;
    }
    int m = (l + r) >> 1;
    mod(b, e, v, pr, i << 1, l, m);
    mod(b, e, v, pr, i << 1 | 1, m + 1, r);
    upd(i);
}
void solve(int T) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int t, u, v, h;
        cin >> t >> u >> v >> h;
        // print("mod", u, v, t == 1 ? h + 1 : -h - 1, i + 1);
        mod(u, v, t == 1 ? h + 1 : -h - 1, i + 1);
    }
    for (int i = 0; i < n; ++i) {
        mod(i, i, 1, k + i);
        // print("???", i, i, 1, k + i);
    }
    for (int i = 0; i < n; ++i) print(maxit[N + i] - 1);
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
        cout << x << '\n';
    }
}
