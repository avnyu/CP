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

void solve() {
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    for (int i = 0; i < h; ++i) cin >> g[i];

    for (auto& i : g)
        for (auto& j : i) j = (j == '.' ? 1 : 0);

    vvi color(h, vi(w));
    vii q(h * w);
    vii step = {{0, 1}, {1, 0}};
    int s = 0;
    q[s++] = {0, 0};
    color[0][0] = 1 + (g[0][0] == 0);

    int l = 0;
    for (int i = color[0][0]; i < h * w + 7; ++i) {
        // write("step", i, l, s);

        for (int j = l; j < s; ++j) {
            for (int k = 0; k < 2; ++k) {
                int u = q[j].fi + step[k].fi;
                int v = q[j].se + step[k].se;
                if (u < h && v < w && !color[u][v] && (g[u][v] & 1) == i % 2) {
                    q[s++] = {u, v};
                    color[u][v] = i;
                    // write("push", u, v, i);
                }
            }
        }

        int stop = s;
        for (int j = l; j < stop; ++j) {
            for (int k = 0; k < 2; ++k) {
                int u = q[j].fi + step[k].fi;
                int v = q[j].se + step[k].se;
                if (u < h && v < w && !color[u][v] && (g[u][v] & 1) != i % 2) {
                    q[s++] = {u, v};
                    color[u][v] = i + 1;
                    // write("push", u, v, i + 1);
                }
            }
        }

        l = stop;

        if (color[h - 1][w - 1]) break;
    }

    write(color[h - 1][w - 1] / 2);
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