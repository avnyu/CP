#include <bits/stdc++.h>

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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

vvii knight(4);

void init_knight_move(int p = 0, int x = 0, int y = 0){
    if (p == 4) return;
    knight[p].push_back({x, y});

    for (int i = -2; i < 3; i += 2)
        for (int j = -1; j < 2; j += 2) {
            init_knight_move(p + 1, x + i, y + j);
            init_knight_move(p + 1, x + j, y + i);
        }
}
// 0: knight, 1: rook, 2: bishop
int dis(ii st, ii ed, int t1, int t2) {
    int res = (t1 != t2);

    if (t1 == 0) {
        for(auto&mv : knight[1]) if(ed.fi == st.fi + mv.fi && ed.se == st.se + mv.se) 
    }

}
void solve() {
    int n;
    cin >> n;
    vii p(n * n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            p[x - 1] = {i, j};
        }

    vvii dp(n * n, vii(3, {n * n * n, 1}));
    for (int i = 1; i < n * n; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k) 
                dp[i][k] = min(dp[i][k], {dp[i][j].fi + dis(p[i - 1], p[i], j, k), dp[i][j].se + (i != j)});
    
    auto res = *min_element(dp[n * n - 1].begin(), dp[n * n - 1].end());
    cout << res.fi << " " << res.se << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

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