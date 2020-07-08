#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vii vector<ii>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
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

bool bpm(vvb& bpGraph, int u, vb& seen, vi& matchR) {
    int M = bpGraph.size();
    int N = M ? bpGraph[0].size() : 0;
    for (int v = 0; v < N; v++)
        if (bpGraph[u][v] && !seen[v]) {
            seen[v] = true;
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR)) {
                matchR[v] = u;
                return true;
            }
        }
    return false;
}
int maxBPM(vvb& bpGraph) {
    int M = bpGraph.size();
    int N = M ? bpGraph[0].size() : 0;
    vi matchR(N, -1);
    int res = 0;
    for (int u = 0; u < M; u++) {
        vb seen(N, false);
        if (bpm(bpGraph, u, seen, matchR)) res++;
    }
    return res;
}
void solve() {
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
