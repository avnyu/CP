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
vvi ed, ps;
vii dr;
#define iii tuple<int, int, int>
deque<iii> dq;

bool solve(int T) {
    int r, c;
    cin >> r >> c;

    if (r == 0 && c == 0) return false;

    ed.assign(r + 2, vi(c + 2, 0));
    ps.assign(r + 2, vi(c + 2, 0));

    vector<vector<char>> a(r + 2, vector<char>(c + 2, '@'));
    for (int i = 0; i++ < r;)
        for (int j = 0; j++ < c;) cin >> a[i][j];

    dq.clear();
    for (int i = 0; i++ < r;) {
        if (a[i][1] != '@' && !ps[i][1]) {
            if (a[i][1] == '#')
                dq.push_front({0, i, 1});
            else
                dq.push_back({1, i, 1});

            ps[i][1] = 1;
        }
        if (a[i][c] != '@') ed[i][c] = 1;
    }
    for (int j = 0; j++ < c;) {
        if (a[r][j] != '@' && !ps[r][j]) {
            if (a[r][j] == '#')
                dq.push_front({0, r, j});
            else
                dq.push_back({1, r, j});

            ps[r][j] = 1;
        }
        if (a[1][j] != '@') ed[1][j] = 1;
    }

    dr.clear();
    for (int i = -1; i < 2; ++i)
        for (int j = -1; j < 2; ++j) dr.push_back({i, j});

    int res = -1;
    while (!dq.empty()) {
        auto [w, ux, uy] = dq.front();
        dq.pop_front();

        if (ed[ux][uy]) {
            res = w;
            break;
        }

        for (auto &add : dr) {
            auto vx = ux + add.fi, vy = uy + add.se;
            if (a[vx][vy] == '@' || ps[vx][vy]) continue;
            if (a[vx][vy] == '#')
                dq.push_front({w, vx, vy});
            else
                dq.push_back({w + 1, vx, vy});
            ps[vx][vy] = 1;
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