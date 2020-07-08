#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vector<int>>
#define vvii vector<vector<ii>>
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
    vvi a(n + 2, vi(m + 2));
    vii b;
    int cnt = 0;
    for (int i = 0; i < n + 2; ++i)
        for (int j = 0; j < m + 2; ++j) {
            if (i == 0 || i == n + 1 || j == 0 || j == m + 1)
                a[i][j] = -1;
            else {
                char c;
                cin >> c;
                if (c == '#')
                    a[i][j] = -1;
                else if (c == '.')
                    a[i][j] = 0;
                else if (c == 'G') {
                    a[i][j] = 1;
                    cnt++;
                } else {
                    a[i][j] = -1;
                    b.push_back({i, j});
                }
            }
        }

    // for (int i = 0; i < n + 2; ++i)
    //     for (int j = 0; j < m + 2; ++j) {
    //         cout << a[i][j] << " \n"[j == m + 1];
    //     }

    vii mov = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (auto& bi : b) {
        for (auto& i : mov) {
            int u, v;
            tie(u, v) = ii{i.fi + bi.fi, i.se + bi.se};
            a[u][v] = -1;
        }
    }
    queue<ii> q;
    if(a[n][m] != -1)q.push({n, m});
    while (!q.empty()) {
        int u, v;
        tie(u, v) = q.front();
        q.pop();

        for (auto& i : mov) {
            int x, y;
            tie(x, y) = ii{u + i.fi, v + i.se};

            if (a[x][y] == 1) {
                a[x][y] = -1;

                cnt--;
                q.push({x, y});
            } else if (a[x][y] == 0) {
                a[x][y] = -1;

                q.push({x, y});
            }
        }
    }
    write((cnt == 0 ? "Yes" : "No"));
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
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