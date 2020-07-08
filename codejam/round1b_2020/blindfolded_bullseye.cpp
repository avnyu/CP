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

int a, b;
vll v(3);

string ask(int x, int y) {
    write(x, y);
    string s;
    cin >> s;
    return s;
}
pair<ii, string> find() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            string s = ask(v[i], v[j]);
            if (s != "MISS") return {{v[i], v[j]}, s};
        }
    return {{0, 0}, {"MISS"}};
}
void solve() {
    auto s = find();
    if (s.second == "CENTER") return;
    int u, d, l, r;
    u = d = s.first.first;
    l = r = s.first.second;

    int mx, my;

    for (int i = 31; i--;) {
        if (u + (1 << i) > int(1e9)) continue;
        string tmp = ask(u + (1 << i), l);
        if (tmp == "CENTER") return;
        if (tmp == "HIT") u += 1 << i;
    }
    for (int i = 31; i--;) {
        if (d - (1 << i) < -int(1e9)) continue;
        string tmp = ask(d - (1 << i), l);
        if (tmp == "CENTER") return;
        if (tmp == "HIT") d -= 1 << i;
    }
    mx = u + d >> 1;

    for (int i = 31; i--;) {
        if (r + (1 << i) > int(1e9)) continue;
        string tmp = ask(mx, r + (1 << i));
        if (tmp == "CENTER") return;
        if (tmp == "HIT") r += 1 << i;
    }
    for (int i = 31; i--;) {
        if (l - (1 << i) < -int(1e9)) continue;
        string tmp = ask(mx, l - (1 << i));
        if (tmp == "CENTER") return;
        if (tmp == "HIT") l -= 1 << i;
    }
    my = l + r >> 1;
    ask(mx, my);
}
int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);
    for (int i = 0; i < 3; ++i) v[i] = 1LL * -5e8 + 1LL * i * 5e8;

    int t = 1;
    cin >> t >> a >> b;
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