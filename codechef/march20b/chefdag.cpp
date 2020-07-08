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

// MBP geeksforgeeks
int n;

bool bpm(vector<vector<bool>>& bpGraph, int u, bool seen[], int matchR[]) {
    for (int v = 0; v < n; v++)
        if (bpGraph[u][v] && !seen[v]) {
            seen[v] = true;
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR)) {
                matchR[v] = u;
                return true;
            }
        }
    return false;
}

void maxBPM(vector<vector<bool>>& bpGraph) {
    int matchR[n];
    memset(matchR, -1, sizeof(matchR));
    int result = 0;
    for (int u = 0; u < n; u++) {
        bool seen[n];
        memset(seen, 0, sizeof(seen));
        if (bpm(bpGraph, u, seen, matchR)) result++;
    }
    cout << n - result << '\n';
    for (int i = 0; i < n; ++i) cout << matchR[i] + 1 << " \n"[i == n - 1];
}

void solve() {
    int k;
    cin >> n >> k;
    vvi a(k, vi(n));
    for (int i = 0; i < k; ++i)
        for (int j = 0; j < n; ++j) cin >> a[i][j];

    vvi num(n + 1, vi(k));
    int res = n;
    vector<vector<bool>> bpGraph(n + 1, vector<bool>(n + 1, false));

    for (int i = 0; i < k; ++i)
        for (int j = 0; j < n; ++j) num[a[i][j]][i] = j;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            int chk = 1;
            for (int l = 0; l < k; ++l)
                if (num[i][l] <= num[j][l]) chk = 0;
            if (chk) bpGraph[i - 1][j - 1] = true;
        }

    maxBPM(bpGraph);
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