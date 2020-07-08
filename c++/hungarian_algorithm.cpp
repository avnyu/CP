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

#define N 55           // max number of vertices in one part
#define INF 100000000  // just infinity
int cost[N][N];        // cost matrix
int n, max_match;      // n workers and n jobs
int lx[N], ly[N];      // labels of X and Y parts
int xy[N];             // xy[x] - vertex that is matched with x,
int yx[N];             // yx[y] - vertex that is matched with y
bool S[N], T[N];       // sets S and T in algorithm
int slack[N];          // as in the algorithm description
int slackx[N];         // slackx[y] such a vertex, that
// l(slackx[y]) + l(y) - w(slackx[y],y) = slack[y]
int prev[N];  // array for memorizing alternating paths

void solve() {}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
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