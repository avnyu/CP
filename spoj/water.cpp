#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
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
template <typename T>
void print_all(vector<T>& a);

void solve() {
    int n, m;
    cin >> n >> m;
    vvi a(n + 2, vi(m + 2, -1));
    for (int i = 0; i++ < n;)
        for (int j = 0; j++ < m;) cin >> a[i][j];

    priority_queue<tuple<int, int, int>> pq;
    for (int i = 0; i++ < n;)
        for (int j = 0; j++ < m;) pq.push({-a[i][j], i, j});

    ll res = 0;
    vector<ii> arr(n * m);
    vector<ii> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vvi done(n + 2, vi(m + 2));

    while (pq.size()) {
        int c, u, v;
        tie(c, u, v) = pq.top();
        pq.pop();

        for (auto& i : done) fill(all(i), 0);
        done[u][v] = 1;

        int l = 0, fill = 1e9;
        arr[l++] = {u, v};
        for (int i = 0; i < l && fill != -1; ++i) {
            for (int k = 0; k < 4; ++k) {
                int x = arr[i].first + moves[k].first;
                int y = arr[i].second + moves[k].second;

                if (done[x][y]) continue;
                done[x][y] = 1;

                if (a[x][y] > a[u][v])
                    fill = min(fill, a[x][y]);
                else if (a[x][y] == a[u][v])
                    arr[l++] = {x, y};
                else
                    fill = -1;
            }
        }

        if (fill == -1) continue;

        res += 1LL * l * (fill - a[u][v]);
        // write("add", u, v, 1LL * l * (fill - a[u][v]));

        for (int i = 0; i < l; ++i) a[arr[i].fi][arr[i].se] = fill;
    }

    cout << res << '\n';
}

int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}

void write() { cout << "\n"; }
template <typename T, typename... Args>
void write(T x, Args... args) {
    cout << x << ' ';
    write(args...);
}
template <typename T>
void print_all(vector<T>& a) {
    for (int i = 0; i < a.size(); ++i) cout << a[i] << " \n"[i == a.size() - 1];
}