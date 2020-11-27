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

const int lgN = 20;
const int N = 2e5 + 7;
vvi st(N, vi(lgN));

void solve(int T) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> st[i][0];

    for (int j = 1; j < lgN; ++j)
        for (int i = 0; i + (1 << j) < n; ++i)
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);

    auto get = [&](int l, int r) {
        int lg = 31 - __builtin_clz(r + 1 - l);
        return min(st[l][lg], st[r + 1 - (1 << lg)][lg]);
    };

    vi pre(n + 2), suf(n + 2);
    for (int i = 0; i < n; ++i) pre[i + 1] = max(pre[i], st[i][0]);
    for (int i = n; i--;) suf[i + 1] = max(suf[i + 2], st[i][0]);

    for (int i = 1; i < n; ++i) {
        int t = i, add = 1 << lgN;
        while (add) {
            if (t + add < n - 1 && get(i, t + add) >= pre[i] &&
                suf[t + add + 2] >= pre[i])
                t += add;
            add >>= 1;
        }
        if (pre[i] == get(i, t) && pre[i] == suf[t + 2]) {
            print("YES");
            print(i, t - i + 1, n - t - 1);
            return;
        }
    }
    print("NO");
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

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