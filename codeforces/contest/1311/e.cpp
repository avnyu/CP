#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define iiii tuple<int, int, int, int>
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
    int n, d;
    cin >> n >> d;
    int low = 0, high = 0, n0 = n - 1;
    for (int i = 0; i < n; ++i) high += i;
    for (int i = 1; i < n; ++i) {
        int y = min(1 << i, n0);
        low += y * i;
        n0 -= y;
        if (n0 == 0) break;
    }
    if (d < low || d > high) {
        cout << "NO\n";
        return;
    }
    vi res(n);
    iota(all(res), 0);

    int j = n;
    ii room = {1, 1};
    while (j--) {
        int h = res[j];
        if (high - (h - room.se) > d) {
            high -= (h - room.se);
            res[j] = room.se;
            room.fi--;

            if (room.fi == 0) {
                room.se++;
                room.fi = (1 << room.se) - 1;
            }
        } else {
            res[j] = h - (high - d);
            break;
        }
    }
    sort(all(res));
    vi cnt(n, 2);

    cout << "YES\n";
    int l = 0;
    for (int i = 1; i < n; ++i) {
        while (res[l] < res[i] - 1 || cnt[l] == 0) l++;
        cnt[l]--;
        cout << l + 1 << " \n"[i == n - 1];
    }
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
    for (auto i = a.begin(); i != a.end();) cout << *i << " \n"[++i == a.end()];
}