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

int ask1(int u) {
    write(1, u);
    cout.flush();
    int t;
    cin >> t;
    if (t == -1) exit(0);
    return t;
}
int ask2(int u, int l) {
    write(2, u, l);
    cout.flush();
    int t;
    cin >> t;
    if (t == -1) exit(0);
    return t;
}
int ans(int u) {
    write(3, u);
    cout.flush();
    int t;
    cin >> t;
    if (t == -1) exit(0);
    return t;
}
void solve() {
    int h;
    cin >> h;

    int t = ask2(1, h);
    int l = ask1(t);
    if (l == 0) {
        ans(t);
        return;
    }

    while (1) {
        t = ask2(t, l);

        if (l > 2)
            l = ask1(t);
        else
            l = 0;

        if (l == 0) {
            ans(t);
            break;
        }
    }
}
int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
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