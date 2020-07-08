#include <bits/stdc++.h>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
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

int n, m;
vi c, d, p, t;
vvi a;

void solve() {
    cin >> n >> m;
    c.assign(n * m, -1);
    d.assign(n * m, 0);
    p.assign(n * m, -1);
    t.assign(n * m, 0);
    a.assign(n * m, vi());

    for (auto& i : c) {
        char c;
        cin >> c;
        i = c == '1';
    }

    for (auto& i : d) {
        char c;
        cin >> c;

        if (c == 'L')
            i = -1;
        else if (c == 'R')
            i = 1;
        else if (c == 'U')
            i = -m;
        else
            i = m;
    }

    for (int i = 0; i < n * m; ++i)
        if (p[i] == -1) {
            int u = i, v = i + d[i];
            stack<int> s;
            s.push(u);
            p[u] = -2;

            while (1) {
                if (p[v] != -1) break;
                s.push(v);
                p[v] = -2;
                u = v;
                v += d[v];
            }

            int r = u, l;
            if (p[v] == -2) {
                while (!s.empty()) {
                    u = s.top();
                    s.pop();
                    p[u] = r;
                    t[u] = a[r].size();
                    a[r].push_back(c[u] == 0);
                    if (u == v) break;
                }
                l = a[r].size();
            } else {
                r = p[v];
                l = t[v] + 1;
            }

            int sz = a[r].size();
            while (!s.empty()) {
                u = s.top();
                s.pop();
                p[u] = r;
                t[u] = l;
                a[r][l % sz] |= (c[u] == 0);
                ++l;
            }
        }

    int rs = 0, rsb = 0;
    for (auto& i : a)
        for (auto& j : i) {
            ++rs;
            rsb += j;
        }
    write(rs, rsb);
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
