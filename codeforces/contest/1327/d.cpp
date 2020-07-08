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

int cal(vi &color, int l) {
    int res = l;
    // write("cal");
    // for (int i = 0; i < l; ++i) cout << color[i] << " \n"[i == l - 1];
    for (int i = 1; i <= l / 2; ++i) {
        if (l % i == 0) {
            for (int st = 0; st < i; ++st) {
                int p = st;
                while (p < l && color[p] == color[st]) p += i;
                if (p >= l) res = min(res, l / i);
            }
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vi p(n + 1), c(n + 1);
    for (int i = 0; i++ < n;) cin >> p[i];
    for (int i = 0; i++ < n;) cin >> c[i];

    int res = 1e9;
    vi color(n + 1), gcd;
    for (int i = 0; i++ < n;) {
        if (p[i] == -1) continue;
        int u = i, l = 0;

        while (p[u] != -1) {
            color[l++] = c[u];
            int prv = u;

            u = p[u];
            p[prv] = -1;
        }

        res = min(res, cal(color, l));
    }
    write(res);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
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