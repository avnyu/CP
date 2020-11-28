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

const int N = 1 << 21;
vi maxit(N << 1), minit(N << 1), addlz(N << 1), remlz(N << 1);
// prior 0 : add first
vi prior(N << 1);

void add(int i, int v) {
    maxit[i] = max(maxit[i], v);
    minit[i] = max(minit[i], v);
    // addlz[i] = v;

    if (v >= addlz[i]) {
        prior[i] = 1;
        addlz[i] = v;
    } else if (!prior[i] && remlz[i] <= v) {
        prior[i] = 1;
        addlz[i] = v;
    } else if (!prior[i] && remlz[i] <= addlz[i]) {
        prior[i] = 1;
        addlz[i] = remlz[i];
    }
}
void rem(int i, int v) {
    maxit[i] = min(maxit[i], v);
    minit[i] = min(minit[i], v);
    // remlz[i] = v;

    if (v <= remlz[i]) {
        prior[i] = 0;
        remlz[i] = v;
    } else if (prior[i] && addlz[i] >= v) {
        prior[i] = 0;
        remlz[i] = v;
    } else if (prior[i] && addlz[i] >= remlz[i]) {
        prior[i] = 0;
        remlz[i] = addlz[i];
    }
}
void push(int i) {
    if (i >= N) return;
    if (!prior[i]) {
        if (addlz[i]) {
            add(i << 1, addlz[i]);
            add(i << 1 | 1, addlz[i]);
            addlz[i] = 0;
        }
        if (remlz[i]) {
            rem(i << 1, remlz[i]);
            rem(i << 1 | 1, remlz[i]);
            remlz[i] = 0;
        }
    } else {
        if (remlz[i]) {
            rem(i << 1, remlz[i]);
            rem(i << 1 | 1, remlz[i]);
            remlz[i] = 0;
        }
        if (addlz[i]) {
            add(i << 1, addlz[i]);
            add(i << 1 | 1, addlz[i]);
            addlz[i] = 0;
        }
    }
}
void upd(int i) {
    maxit[i] = max(maxit[i << 1], maxit[i << 1 | 1]);
    minit[i] = min(minit[i << 1], minit[i << 1 | 1]);
}
void mod(int b, int e, int v, int i = 1, int l = 0, int r = N - 1) {
    push(i);
    if (l > e || r < b) return;
    if (b <= l && r <= e) {
        if (v > 0)
            add(i, v);
        else
            rem(i, -v);
        return;
    }
    int m = (l + r) >> 1;
    mod(b, e, v, i << 1, l, m);
    mod(b, e, v, i << 1 | 1, m + 1, r);
    upd(i);
}
void solve(int T) {
    int n, k;
    cin >> n >> k;
    for (; k--;) {
        int t, u, v, h;
        cin >> t >> u >> v >> h;
        mod(u, v, t == 1 ? h + 1 : -h - 1);
    }
    for (int i = 0; i < n; ++i) mod(i, i, 1);
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