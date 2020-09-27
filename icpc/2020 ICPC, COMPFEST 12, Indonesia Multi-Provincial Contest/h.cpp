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

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void solve() {
    int a, b, c, d;
    cin >> b >> a >> c >> d;
    vector<string> rs = {"Tidak", "Ya"};
    vi ans(4, 0);
    if ((a + b) & 1) {
        if (!a && !c)
            ans[0] = 1;
        else if (!b && !d)
            ans[1] = 1;
        else
            ans[0] = ans[1] = 1;
    } else {
        if (!a && !c)
            ans[3] = 1;
        else if (!b && !d)
            ans[2] = 1;
        else
            ans[2] = ans[3] = 1;
    }
    for (int i = 0; i < 4; ++i) cout << rs[ans[i]] << " \n"[i == 3];
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

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