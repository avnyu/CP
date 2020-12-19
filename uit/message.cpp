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

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void solve(int T) {
    int n, q;
    cin >> n >> q;
    // hs = 0, gv = 1, ht = 2
    vvi type = {{1, 1, 1}, {1, 1, 3}, {1, 2, 1}};
    vvi query(q);
    vi a(n + 1), cnt(n + 1, 0);
    int cntgv = 0, cntht = 0;
    for (int i = 0; i++ < n;) cin >> a[i];
    for (int i = 0; i < q; ++i) {
        int t, u, v, x;
        cin >> t;
        if (t == 1) {
            cin >> u >> v;
            if (type[a[u]][a[v]] == 1) {
                cnt[v]++;
            } else if (type[a[u]][a[v]] == 2) {
                cntgv++;
                cntht++;
            } else if (type[a[u]][a[v]] == 3) {
                cntht++;
                cnt[v]++;
            }
        } else if (t == 2) {
            cin >> u >> x;
            int &qu = a[query[x - 1][1]], &qv = a[query[x - 1][2]];
            if (type[qu][qv] == 1)
                cnt[u]--;
            else if (type[qu][qv] == 2) {
                if (a[u] == 0)
                    cntht--;
                else if (a[u] == 1)
                    cntgv--;
            } else {
                if (a[u] == 0)
                    cntht--;
                else if (a[u] == 2)
                    cnt[u]--;
            }
        } else {
            cin >> u;
            if (a[u] == 0)
                cout << cnt[u] + cntht << '\n';
            else if (a[u] == 1)
                cout << cnt[u] + cntgv << '\n';
            else
                cout << cnt[u] << '\n';
        }
        query[i] = vi{t, u, v};
        // for (int j = 0; j++ < n;) cout << cnt[j] << " \n"[j == n];
        // print(cntht, cntgv);
    }
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