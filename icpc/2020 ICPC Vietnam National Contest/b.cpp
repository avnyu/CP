#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

int mr, mc;
vi dr, ed(2e6 + 7), ps(2e6 + 7);
vvi tf;
deque<ii> dq;

bool solve(int T) {
    int r, c;
    cin >> r >> c;
    mr = r + 7, mc = c + 7;

    if (r == 0 && c == 0) return false;

    vector<vector<char>> a(r + 2, vector<char>(c + 2, '@'));
    for (int i = 0; i++ < r;)
        for (int j = 0; j++ < c;) cin >> a[i][j];

    tf.resize(mr, vi(mc, 0));
    for (int i = 0; i < mr; ++i)
        for (int j = 0; j < mc; ++j) tf[i][j] = i * mc + j;

    for (int i = 0; i < mr * mc; ++i) ed[i] = ps[i] = 0;
    for (int i = 0; i++ < r;) {
        if (a[i][1] != '@' && !ps[tf[i][1]]) {
            if (a[i][1] == '!')
                dq.push_front({0, tf[i][1]});
            else
                dq.push_back({1, tf[i][1]});

            ps[tf[i][1]] = 1;
        }
        if (a[i][c] != '@') ed[i * mc + c] = 1;
    }
    for (int j = 0; j++ < c;) {
        if (a[r][j] != '@' && !ps[tf[r][j]]) {
            if (a[r][j] == '!')
                dq.push_front({0, tf[r][j]});
            else
                dq.push_back({1, tf[r][j]});

            ps[tf[r][1]] = 1;
        }
        if (a[1][j] != '@') ed[1 * mc + j] = 1;
    }

    dr.clear();
    for (int i = -1; i < 2; ++i)
        for (int j = -1; j < 2; ++j) {
            if (i + j == 0) continue;
            dr.push_back(i * mc + j);
        }

    int res = 0;
    while (!dq.empty()) {
        auto &[w, u] = dq.front();
        dq.pop_front();

        if (ed[u]) {
            res = w;
            break;
        }

        for (auto &add : dr) {
            auto v = u + add;
            if (a[v / mc][v % mc] == '@' || ps[v]) continue;
            if (a[v / mc][v % mc] == '!')
                dq.push_front({w, v});
            else
                dq.push_back({w + 1, v});
            ps[v] = 1;
        }
    }

    cout << res << '\n';
    return true;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    // int t = 1;
    // cin >> t;
    // for (int i = 0; i++ < t;) solve(i);

    while (1) {
        if (!solve(0)) break;
    }

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