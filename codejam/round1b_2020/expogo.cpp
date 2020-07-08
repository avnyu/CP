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

const string x = "IMPOSSIBLE";
string ans, s;

void out(int t) { cout << "Case #" << t << ": " << ans << endl; }
bool dfs(int n, int m, int step = 31) {
    if (n == 0 && m == 0) {
        // write("YES", 31 - step);
        if (ans == x || ans.size() > s.size()) ans = s;
        return true;
    }
    if (!step) return false;
    if (!(n + m & 1)) return false;

    // write("dfs", n, m, step);
    if (abs(n) & 1) {
        s.push_back(n > 0 ? 'E' : 'W');
        dfs(n - (s.back() == 'E' ? 1 : -1) >> 1, m >> 1, step - 1);
        s.back() = s.back() == 'E' ? 'W' : 'E';
        dfs(n - (s.back() == 'E' ? 1 : -1) >> 1, m >> 1, step - 1);
        s.pop_back();
    } else {
        s.push_back(n > 0 ? 'S' : 'N');
        dfs(n >> 1, m + (s.back() == 'S' ? 1 : -1) >> 1, step - 1);
        s.back() = s.back() == 'S' ? 'N' : 'S';
        dfs(n >> 1, m + (s.back() == 'S' ? 1 : -1) >> 1, step - 1);
        s.pop_back();
    }

    return false;
}
void solve(int t) {
    int n, m;
    cin >> n >> m;

    ans = x;
    s = "";

    dfs(n, m);

    // if (ans != x) reverse(all(ans));

    out(t);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    for (int i = 0; i++ < t;) solve(i);

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