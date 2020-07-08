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
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    queue<ii> q;
    q.push({0, 0});
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vi time(h);
    for (int i = 0; i < n; ++i) {
        fill(all(time), -1);
        int n = q.size();
        while (q.size()) {
            int t, cnt;
            tie(t, cnt) = q.front();
            q.pop();

            int t1 = (t + a[i]) % h, t2 = (t + a[i] - 1 + h) % h;
            time[t1] = max(time[t1], cnt + (t1 >= l && t1 <= r));
            time[t2] = max(time[t2], cnt + (t2 >= l && t2 <= r));
        }
        for (int j = 0; j < h; ++j)
            if (time[j] > -1) q.push({j, time[j]});
    }

    int res = 0;
    while (q.size()) {
        int t, cnt;
        tie(t, cnt) = q.front();
        q.pop();

        res = max(res, cnt);
    }
    
    cout << res << '\n';
}

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